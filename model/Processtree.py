import pm4py
import itertools


class Node:

    def __init__(self, value, children=None):
        if children is None:
            children = []
        self.value = value
        self.children = children

    def is_leaf(self):
        return len(self.children) == 0

    def to_string(self, level):
        if self.value == "":
            ret = "  " * level + "tau" + "\n"
        else:
            ret = "  " * level + str(self.value) + "\n"
        for child in self.children:
            ret += child.__str__(level+1)
        return ret

    def __str__(self):
        if self.value == "":
            ret = "  " + "tau" + "\n"
        else:
            ret = "  " + str(self.value) + "\n"

class Seq(Node):

    def __init__(self, node_id, children):
        super().__init__("Seq " + str(node_id), children=children)
        permutations = itertools.permutations(range(len(children)))
        self.O = {"".join(map(str, perm)): 0 for perm in permutations}
        self.O["".join(str(i) for i in range(len(children)))] = 1

    def assign_prob(self, probs):
        pass

    def to_string(self, level):
        ret = "  " * level + self.value + " -> " + str(self.O) + "\n"
        for child in self.children:
            ret += child.to_string(level+1)
        return ret

    def __str__(self):
        ret = "  " + str(self.value) + " -> " + str(self.O) + "\n"

class BinaryChoice(Node):

    def __init__(self, node_id, children, wi):
        super().__init__("Binary Choice " + str(node_id), children=children)
        self.wi = wi
        self.p = [0.5, 0.5]

    def assign_prob(self, probs):
        self.p = [probs[self.wi], 1-probs[self.wi]]

    def to_string(self, level):
        ret = "  " * level + self.value + " -> " + str(self.p) + " | (" + str(self.wi) + ")\n"
        for child in self.children:
            ret += child.to_string(level+1)
        return ret

    def __str__(self):
        ret = "  " + str(self.value) + " -> " + str(self.p) + " | (" + str(self.wi) + ")\n"

class Choice(Node):

    def __init__(self, node_id, children, wi_start, wi_end):
        super().__init__("Choice " + str(node_id), children=children)
        self.wi_start, self.wi_end = wi_start, wi_end
        self.p = [1/len(children) for _ in range(len(children))]

    def assign_prob(self, probs):
        self.p = [x/sum(probs[self.wi_start:self.wi_end+1]) for x in probs[self.wi_start:self.wi_end+1]]

    def to_string(self, level):
        ret = "  " * level + self.value + " -> " + str(self.p) + " | (" + str(self.wi_start) + "," + str(self.wi_end) + ")\n"
        for child in self.children:
            ret += child.to_string(level+1)
        return ret

    def __str__(self):
        ret = "  " + str(self.value) + " -> " + str(self.p) + " | (" + str(self.wi_start) + "," + str(self.wi_end) + ")\n"

class BinaryParallel(Node):

    def __init__(self, node_id, children, wi, ev_language):
        super().__init__("Binary Parallel " + str(node_id), children=children)
        self.wi = wi
        self.p = [0.5, 0.5]

    def assign_prob(self, probs):
        self.p = [probs[self.wi], 1-probs[self.wi]]

    def to_string(self, level):
        ret = "  " * level + self.value + " -> " + str(self.p) + " | (" + str(self.wi) + ")\n"
        for child in self.children:
            ret += child.to_string(level+1)
        return ret

    def __str__(self):
        ret = "  " + str(self.value) + " -> " + str(self.p) + " | (" + str(self.wi) + ")\n"

class Parallel(Node):

    def __init__(self, node_id, children, wi_start, wi_end, ev_language):
        super().__init__("Parallel " + str(node_id), children=children)
        self.wi_start, self.wi_end = wi_start, wi_end
        self.p = [1/len(children) for _ in range(len(children))]

    def assign_prob(self, probs):
        self.p = [x/sum(probs[self.wi_start:self.wi_end+1]) for x in probs[self.wi_start:self.wi_end+1]]

    def to_string(self, level):
        ret = "  " * level + self.value + " -> " + str(self.p) + " | (" + str(self.wi_start) + "," + str(self.wi_end) + ")\n"
        for child in self.children:
            ret += child.to_string(level+1)
        return ret

    def __str__(self):
        ret = "  " + str(self.value) + " -> " + str(self.p) + " | (" + str(self.wi_start) + "," + str(self.wi_end) + ")\n"

class Loop(Node):

    def __init__(self, node_id, children, wi, max_loop, ev_language):
        super().__init__("Loop " + str(node_id), children=children)
        self.wi = wi
        self.p = 0.5
        self.max_loop = max_loop

    def assign_prob(self, probs):
        self.p = probs[self.wi]

    def to_string(self, level):
        ret = "  " * level + self.value + " -> " + str(self.p) + " | (" + str(self.wi) + ")\n"
        for child in self.children:
            ret += child.to_string(level+1)
        return ret

    def __str__(self):
        ret = "  " + str(self.value) + " -> " + str(self.p) + " | (" + str(self.wi) + ")\n"

class StochasticProcessTree:

    def __init__(self, tree, root, nodes, size_p, noise_threshold):
        self.tree = tree
        self.root, self.nodes, self.size_p = root, nodes, size_p
        self.noise_threshold = noise_threshold

    def assign_prob(self, probs):
        for node in self.nodes:
            node.assign_prob(probs)

    def get_prob(self):
        probs = [0 for _ in range(self.size_p)]
        for node in self.nodes:
            if type(node) is BinaryChoice or type(node) is BinaryParallel:
                probs[node.wi] = node.p[0]
            if type(node) is Loop:
                probs[node.wi] = node.p
            elif type(node) is Choice or type(node) is Parallel:
                probs[node.wi_start:node.wi_end] = node.p
        return probs

    def __str__(self):
        if self.tree is not None:
            pm4py.view_process_tree(self.tree)
        return self.root.to_string(0)

    ####################################################################################################

    def export_ptml(self, filename):
        pm4py.write_ptml(self.tree, filename)

    ####################################################################################################
