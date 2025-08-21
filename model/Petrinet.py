import pm4py

from graphviz import Digraph
from pm4py.visualization.transition_system import visualizer as rg_visualizer


class Place:

    def __init__(self, name, tokens=0):
        self.name = name
        self.tokens = tokens

    def get_name(self):
        return self.name

    def get_tokens(self):
        return self.tokens

    def __str__(self):
        return "(" + str(self.name) + "," + str(self.tokens) + ")"

    def __repr__(self):
        return self.__str__()

class Transition:

    def __init__(self, name, label, weight=1):
        self.name = name
        self.label = label
        self.weight = weight
        self.silent = self.label is None

    def get_name(self):
        return self.name

    def get_label(self):
        return self.label

    def get_weight(self):
        return self.weight

    def is_silent(self):
        return self.silent

    def set_weight(self, weight):
        self.weight = weight

    def __str__(self):
        return "(" + str(self.name) + "," + str(self.label) + "," + str(self.weight) + ")"

    def __repr__(self):
        return self.__str__()

class Arc:

    def __init__(self, source, target, multiplicity):
        self.source = source
        self.target = target
        self.multiplicity = multiplicity

    def get_source(self):
        return self.source

    def get_target(self):
        return self.target

    def get_multiplicity(self):
        return self.multiplicity

    def __str__(self):
        return "(" + str(self.source) + "," + str(self.target) + "," + str(self.multiplicity) + ")"

    def __repr__(self):
        return self.__str__()

# P -> T
class InArc(Arc):
    def __init__(self, source, target, multiplicity=1):
        super().__init__(source, target, multiplicity)

# T -> P
class OutArc(Arc):
    def __init__(self, source, target, multiplicity=1):
        super().__init__(source, target, multiplicity)

class Petrinet:

    def __init__(self, net, im, fm, places, transitions, inarcs, outarcs, dir_places, dir_transitions, tr2lab, start, end, max_activities):
        self.net, self.im, self.fm = net, im, fm
        self.places, self.transitions = places, transitions
        self.inarcs, self.outarcs = inarcs, outarcs
        self.dir_places, self.dir_transitions, self.tr2lab = dir_places, dir_transitions, tr2lab
        self.start, self.end = start, end
        self.max_activities = max_activities
        self.rg = pm4py.objects.petri_net.utils.reachability_graph.construct_reachability_graph(self.net, self.im, True)

    def get_net(self):
        return self.net

    def get_im(self):
        return self.im

    def get_fm(self):
        return self.fm

    def get_places(self):
        return self.places

    def get_transitions(self):
        return self.transitions

    def get_inarcs(self):
        return self.inarcs

    def get_outarcs(self):
        return self.outarcs

    def get_dir_places(self):
        return self.dir_places

    def get_dir_transitions(self):
        return self.dir_transitions

    def get_tr2lab(self):
        return self.tr2lab

    def get_max_activities(self):
        return self.max_activities

    def get_rg(self):
        return self.rg

    def set_weights(self, weights):
        for transition in self.transitions:
            transition.set_weight(weights[transition.get_name()])

    def view_petri_net(self, w):
        dot = Digraph(graph_attr={'rankdir': 'LR'})
        for place in self.net.places:
            dot.node(place.name, label=place.name, shape="circle")
        for t,transition in enumerate(self.net.transitions):
            if transition.label is not None:
                label = transition.label + " \n (" + str(w[t]) + ")"
            else:
                label = transition.name + " \n (" + str(w[t]) + ")"
            dot.node(transition.name, label=label, shape="box")
        for arc in self.net.arcs:
            dot.edge(arc.source.name, arc.target.name)
        dot.render("pn", format='png', view=True)

    def show_rg(self):
        gviz = rg_visualizer.apply(self.rg, parameters={rg_visualizer.Variants.VIEW_BASED.value.Parameters.FORMAT: "png"})
        rg_visualizer.view(gviz)

    def __str__(self):
        if self.net is not None:
            pm4py.view_petri_net(self.net, self.im, self.fm)
        result = "Places: ["
        for pl in self.places:
            result += pl.__str__() + ","
        result = result[:-1] + "]\n" + "Transitions: ["
        for tr in self.transitions:
            result += tr.__str__() + ","
        result = result[:-1] + "]\n" + "Inarcs: ["
        for ia in self.inarcs:
            result += ia.__str__() + ","
        result = result[:-1] + "]\n" + "Outarcs: ["
        for oa in self.outarcs:
            result += oa.__str__() + ","
        return result[:-1] + "]"

    ####################################################################################################

    def export_pnml(self, filename):
        pm4py.write_pnml(self.net, self.im, self.fm, filename)

    ####################################################################################################
