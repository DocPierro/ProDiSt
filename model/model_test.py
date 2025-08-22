from log.Eventlog import EventLog
from model.Petrinet import Place, Transition, InArc, OutArc, StochasticPetriNet


def test_place():

    p1 = Place("p1", 2)
    p2 = Place("p2")

    assert p1.get_name() == "p1"
    assert p2.get_name() == "p2"
    assert p1.get_tokens() == 2
    assert p2.get_tokens() == 0

    assert p1.__str__() == "(p1,2)"
    assert p2.__str__() == "(p2,0)"

def test_transition():

    t1 = Transition("t1", "a")
    t2 = Transition("t2", None, 2)

    assert t1.get_name() == "t1"
    assert t2.get_name() == "t2"
    assert t1.get_label() == "a"
    assert t2.get_label() is None
    assert t1.get_weight() == 1
    assert t2.get_weight() == 2
    assert t1.is_silent() == False
    assert t2.is_silent() == True

    t1.set_weight(3)
    assert t1.get_weight() == 3

    assert t1.__str__() == "(t1,a,3)"
    assert t2.__str__() == "(t2,None,2)"

def test_inarc():

    p1 = Place("p1")
    t1 = Transition("t1", None)
    ia1 = InArc(p1, t1, 1)

    assert ia1.get_source() == p1
    assert ia1.get_target() == t1
    assert ia1.get_multiplicity() == 1

    assert ia1.__str__() == "((p1,0),(t1,None,1),1)"

def test_outarc():

    t1 = Transition("t1", None)
    p1 = Place("p1")
    oa1 = OutArc(t1, p1, 1)

    assert oa1.get_source() == t1
    assert oa1.get_target() == p1
    assert oa1.get_multiplicity() == 1

    assert oa1.__str__() == "((t1,None,1),(p1,0),1)"

def test1_petrinet():

    ev = EventLog("../toy_data/ex1.xes")
    pn_alpha = ev.discover_pn_alpha()
    pn_inductive = ev.discover_pn_inductive()

    print(pn_alpha)
    print(pn_inductive)

def test2_petrinet():

    ev = EventLog("../toy_data/ex1.xes")
    pn_alpha = ev.import_PN_pnml("../toy_data/ex1_alpha.pnml")
    pn_inductive = ev.import_PN_pnml("../toy_data/ex1_inductive.pnml")

    print(pn_alpha)
    print(pn_inductive)

def test1_processtree():

    ev = EventLog("../toy_data/ex1.xes")
    pt_inductive = ev.discover_pt_inductive()

    print(pt_inductive)

def test2_processtree():

    ev = EventLog("../toy_data/ex1.xes")
    pt_inductive = ev.import_PT_pnml("../toy_data/ex1_inductive.ptml")

    print(pt_inductive)
