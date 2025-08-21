import pm4py
import xml.etree.ElementTree as ET

from pm4py.statistics.variants.log import get as variants_module

from model.Petrinet import Place, Transition, InArc, OutArc, Petrinet


class Event:

    def __init__(self, case, activity, timestamp):
        self.case = case
        self.activity = activity
        self.timestamp = timestamp

    def get_case(self):
        return self.case

    def get_activity(self):
        return self.activity

    def get_timestamp(self):
        return self.timestamp

    def __str__(self):
        return ("Case: " + str(self.case) +
                "; Activity: " + str(self.activity) +
                "; Timestamp: " + str(self.timestamp) + ";")

    def __repr__(self):
        return self.__str__()

class Trace:

    def __init__(self, tid, seq, word, freq, prob, mapping):
        self.tid = tid
        self.seq, self.word = seq, word
        self.freq, self.prob = freq, prob
        self.mapping = mapping

    def get_tid(self):
        return self.tid

    def get_word(self):
        return self.word

    def get_seq(self):
        return self.seq

    def get_freq(self):
        return self.freq

    def get_prob(self):
        return self.prob

    def get_mapping(self):
        return self.mapping

    def map(self, mapping):
        self.mapping = mapping

    def __str__(self):
        return "(" + str(self.tid) + ",<" + str(self.seq) + ">," + str(self.freq) + "," + str(self.prob) + "," + str(self.mapping) + ")"

    def __repr__(self):
        return self.__str__()

class Eventlog:

    def __init__(self, filename):

        self.log = pm4py.read.read_xes(filename)

        self.language = []
        self.language_pm4py = variants_module.get_language(self.log)
        if "case:frequency" in self.log:
            frequencies = [int(trace.find("int").attrib["value"]) for trace in ET.parse(filename).getroot().findall("trace")]
            for i, seq in enumerate(self.language_pm4py):
                self.language.append(Trace(i, seq, "".join(seq), int(frequencies[i]), int(frequencies[i]) / sum(frequencies), -1))
        else:
            cases = pm4py.get_event_attribute_values(self.log, "case:concept:name")
            for i, seq in enumerate(self.language_pm4py):
                self.language.append(Trace(i, seq, "".join(seq), self.language_pm4py[seq] * len(cases), self.language_pm4py[seq], -1))

        self.prefixes = self.build_prefix_set()
        self.longest_trace_size = max(len(trace.get_seq()) for trace in self.language)

        self.activities = {activity: mapping + 1 for mapping, activity in enumerate(pm4py.get_event_attribute_values(self.log, "concept:name"))}
        self.max_activities = self.build_max_activities()

        for trace in self.language:
            trace_mapping = 0
            for c, activity in enumerate(trace.get_seq()):
                trace_mapping += self.activities[activity] * pow(len(self.activities), c)
            trace.map(trace_mapping)

    def get_log(self):
        return self.log

    def get_language(self):
        return self.language

    def get_language_pm4py(self):
        return self.language_pm4py

    def get_prefixes(self):
     return self.prefixes

    def get_longest_trace_size(self):
        return self.longest_trace_size

    def get_activities(self):
        return self.activities

    def get_max_activities(self):
        return self.max_activities

    def __str__(self):
        result = "["
        for trace in self.language:
            result += trace.__str__() + ",\n"
        return result[:-2] + "]"

    ####################################################################################################

    def build_prefix_set(self):
        prefixes = set()
        prefixes.add(tuple([]))
        for trace in self.language:
            prefix = []
            for activity in trace.get_seq():
                prefix.append(activity)
                if tuple(prefix) not in prefixes:
                    prefixes.add(tuple(prefix))
        return prefixes

    def build_max_activities(self):
        max_activities = dict(zip(self.activities, [0 for _ in range(len(self.activities))]))
        for trace in self.language:
            for activity in self.activities:
                count = trace.get_seq().count(activity)
                if count > max_activities[activity]:
                    max_activities[activity] = count
        return max_activities

    ####################################################################################################

    def import_PN_pnml(self, filename):

        net, im, fm = pm4py.read_pnml(filename)

        places, dir_places = [], {}
        pl_start, pl_end = None, None
        implace, fmplace = next(iter(im)).name, next(iter(fm)).name

        for p, place in enumerate(net.places):
            if place.name == implace:
                place.name = "start"
                pl_start = Place("start")
                dir_places[place] = pl_start
                places.append(pl_start)
            elif place.name == fmplace:
                place.name = "end"
                pl_end = Place("end")
                dir_places[place] = pl_end
                places.append(pl_end)
            else:
                place.name = "p" + str(p)
                pl_i = Place("p" + str(p))
                dir_places[place] = pl_i
                places.append(pl_i)

        transitions, dir_transitions, tr2lab = [], {}, {}
        for t, transition in enumerate(net.transitions):
            transition.name = "t" + str(t)
            tr_i = Transition("t" + str(t), transition.label)
            dir_transitions[transition] = tr_i
            transitions.append(tr_i)
            tr2lab["t" + str(t)] = transition.label

        inarcs, outarcs = [], []
        for arc in net.arcs:
            if isinstance(arc.source, pm4py.objects.petri_net.obj.PetriNet.Place):
                source = dir_places[arc.source]
                target = dir_transitions[arc.target]
                inarcs.append(InArc(source, target))
            elif isinstance(arc.source, pm4py.objects.petri_net.obj.PetriNet.Transition):
                source = dir_transitions[arc.source]
                target = dir_places[arc.target]
                outarcs.append(OutArc(source, target))

        return Petrinet(net, im, fm, places, transitions, inarcs, outarcs, dir_places, dir_transitions, tr2lab,
                        pl_start, pl_end, self.get_max_activities())

    def import_SPN_pnml(self, filename):

        net, im, fm = pm4py.read_pnml(filename)

        root = ET.parse(filename).getroot()
        ns = {'pnml': 'http://www.pnml.org/version-2009/grammar/pnml'}
        element_to_parent, weights = {}, {}
        for parent in root.iter():
            for child in parent:
                element_to_parent[child] = parent  # Store parent of each child
        for toolspecific in root.findall(".//toolspecific", ns):
            if toolspecific.attrib.get("tool") == "StochasticPetriNet":
                parent = element_to_parent.get(toolspecific)
                if parent is not None:
                    properties = {prop.attrib["key"]: prop.text for prop in toolspecific.findall("property", ns)}
                    weights[parent.attrib.get('id', 'Unknown')] = float(properties["weight"])

        places, dir_places = [], {}
        pl_start, pl_end = None, None
        implace, fmplace = next(iter(im)).name, next(iter(fm)).name

        for p, place in enumerate(net.places):
            if place.name == implace:
                place.name = "start"
                pl_start = Place("start")
                dir_places[place] = pl_start
                places.append(pl_start)
            elif place.name == fmplace:
                place.name = "end"
                pl_end = Place("end")
                dir_places[place] = pl_end
                places.append(pl_end)
            else:
                place.name = "p" + str(p)
                pl_i = Place(place.name)
                dir_places[place] = pl_i
                places.append(pl_i)

        transitions, dir_transitions, tr2lab, previous_name = [], {}, {}, {}
        for t, transition in enumerate(net.transitions):
            tr_i = Transition(transition.name, transition.label)
            tr_i.set_weight(weights[transition.name])
            dir_transitions[transition] = tr_i
            transitions.append(tr_i)
            tr2lab[transition.name] = transition.label

        inarcs, outarcs = [], []
        for arc in net.arcs:
            if isinstance(arc.source, pm4py.objects.petri_net.obj.PetriNet.Place):
                source = dir_places[arc.source]
                target = dir_transitions[arc.target]
                inarcs.append(InArc(source, target))
            elif isinstance(arc.source, pm4py.objects.petri_net.obj.PetriNet.Transition):
                source = dir_transitions[arc.source]
                target = dir_places[arc.target]
                outarcs.append(OutArc(source, target))

        return Petrinet(net, im, fm, places, transitions, inarcs, outarcs, dir_places, dir_transitions, tr2lab,
                        pl_start, pl_end, self.get_max_activities())

    ####################################################################################################

    def discover_pn_alpha(self):

        net, im, fm = pm4py.discovery.discover_petri_net_alpha(self.log,
                                                               case_id_key="case:concept:name",
                                                               activity_key="concept:name",
                                                               timestamp_key="time:timestamp")

        places, dir_places = [], {}
        pl_start, pl_end = None, None
        implace, fmplace = next(iter(im)).name, next(iter(fm)).name

        for p, place in enumerate(net.places):
            if place.name == implace:
                place.name = "start"
                pl_start = Place("start")
                dir_places[place] = pl_start
                places.append(pl_start)
            elif place.name == fmplace:
                place.name = "end"
                pl_end = Place("end")
                dir_places[place] = pl_end
                places.append(pl_end)
            else:
                place.name = "p" + str(p)
                pl_i = Place("p" + str(p))
                dir_places[place] = pl_i
                places.append(pl_i)

        transitions, dir_transitions, tr2lab = [], {}, {}
        for t, transition in enumerate(net.transitions):
            transition.name = "t" + str(t)
            tr_i = Transition("t" + str(t), transition.label)
            dir_transitions[transition] = tr_i
            transitions.append(tr_i)
            tr2lab["t" + str(t)] = transition.label

        inarcs, outarcs = [], []
        for arc in net.arcs:
            if isinstance(arc.source, pm4py.objects.petri_net.obj.PetriNet.Place):
                source = dir_places[arc.source]
                target = dir_transitions[arc.target]
                inarcs.append(InArc(source, target))
            elif isinstance(arc.source, pm4py.objects.petri_net.obj.PetriNet.Transition):
                source = dir_transitions[arc.source]
                target = dir_places[arc.target]
                outarcs.append(OutArc(source, target))

        return Petrinet(net, im, fm, places, transitions, inarcs, outarcs, dir_places, dir_transitions, tr2lab,
                        pl_start, pl_end, self.get_max_activities())

    def discover_pn_inductive(self, noise_threshold=0):

        net, im, fm = pm4py.discovery.discover_petri_net_inductive(self.log,
                                                                   case_id_key="case:concept:name",
                                                                   activity_key="concept:name",
                                                                   timestamp_key="time:timestamp",
                                                                   noise_threshold=noise_threshold)

        places, dir_places = [], {}
        pl_start, pl_end = None, None
        implace, fmplace = next(iter(im)).name, next(iter(fm)).name

        for p, place in enumerate(net.places):
            if place.name == implace:
                place.name = "start"
                pl_start = Place("start")
                dir_places[place] = pl_start
                places.append(pl_start)
            elif place.name == fmplace:
                place.name = "end"
                pl_end = Place("end")
                dir_places[place] = pl_end
                places.append(pl_end)
            else:
                place.name = "p" + str(p)
                pl_i = Place("p" + str(p))
                dir_places[place] = pl_i
                places.append(pl_i)

        transitions, dir_transitions, tr2lab = [], {}, {}
        for t, transition in enumerate(net.transitions):
            transition.name = "t" + str(t)
            tr_i = Transition("t" + str(t), transition.label)
            dir_transitions[transition] = tr_i
            transitions.append(tr_i)
            tr2lab["t" + str(t)] = transition.label

        inarcs, outarcs = [], []
        for arc in net.arcs:
            if isinstance(arc.source, pm4py.objects.petri_net.obj.PetriNet.Place):
                source = dir_places[arc.source]
                target = dir_transitions[arc.target]
                inarcs.append(InArc(source, target))
            elif isinstance(arc.source, pm4py.objects.petri_net.obj.PetriNet.Transition):
                source = dir_transitions[arc.source]
                target = dir_places[arc.target]
                outarcs.append(OutArc(source, target))

        return Petrinet(net, im, fm, places, transitions, inarcs, outarcs, dir_places, dir_transitions, tr2lab,
                        pl_start, pl_end, self.get_max_activities())

    ####################################################################################################