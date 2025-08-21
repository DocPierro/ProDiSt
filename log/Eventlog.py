import pm4py
import xml.etree.ElementTree as ET

from pm4py.statistics.variants.log import get as variants_module


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
