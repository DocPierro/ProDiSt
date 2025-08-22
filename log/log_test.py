from log.Eventlog import Event, Trace, EventLog


def test_event():

    a1 = Event("1", "a", "2012-12-30T00:00:00")

    assert a1.get_case() == "1"
    assert a1.get_activity() == "a"
    assert a1.get_timestamp() == "2012-12-30T00:00:00"

    assert a1.__str__() == "Case: 1; Activity: a; Timestamp: 2012-12-30T00:00:00;"

def test_trace():

    t1 = Trace("0", ("a", "b", "c"), "abc", 1, 1, -1)

    assert t1.get_tid() == "0"
    assert t1.get_seq() == ("a", "b", "c")
    assert t1.get_word() == "abc"
    assert t1.get_freq() == 1
    assert t1.get_prob() == 1
    assert t1.get_mapping() == -1

    t1.map(-2)
    assert t1.get_mapping() == -2

    assert t1.__str__() == "(0,<('a', 'b', 'c')>,1,1,-2)"

def test_eventlog():

    ev1 = EventLog("../toy_data/ex1.xes")

    assert ev1.get_prefixes() == {(), ('a',), ('a', 'c'), ('a', 'c', 'c'), ('a', 'c', 'c', 'd'), ('a', 'c', 'c', 'd', 'e'), ('a', 'c', 'd'), ('a', 'c', 'd', 'e'), ('b',), ('b', 'c'), ('b', 'c', 'd'), ('b', 'c', 'd', 'e'), ('c',), ('c', 'a'), ('c', 'a', 'c'), ('c', 'a', 'c', 'd'), ('c', 'a', 'c', 'd', 'f'), ('c', 'b'), ('c', 'b', 'd'), ('c', 'b', 'd', 'f')}
    assert ev1.get_longest_trace_size() == 5
    assert ev1.get_activities() == {'a': 3, 'b': 5, 'c': 1, 'd': 2, 'e': 4, 'f': 6}
    assert ev1.get_max_activities() == {'a': 1, 'b': 1, 'c': 2, 'd': 1, 'e': 1, 'f': 1}

    assert ev1.__str__() == ("[(0,<('a', 'c', 'd', 'e')>,30,0.3,945),\n"
                                "(1,<('b', 'c', 'd', 'e')>,25,0.25,947),\n"
                                "(2,<('c', 'b', 'd', 'f')>,20,0.2,1399),\n"
                                "(3,<('a', 'c', 'c', 'd', 'e')>,15,0.15,5661),\n"
                                "(4,<('c', 'a', 'c', 'd', 'f')>,10,0.1,8263)]")
