import warnings

from Optimizer_SPN.simulation_based_InfBayes import SbIB
from log.Eventlog import EventLog


if __name__ == '__main__':
    warnings.filterwarnings("ignore")

    ev = EventLog("rl_data/BPIC13_open/BPIC13_open.xes")
    pn = ev.discover_pn_inductive()
    sbib = SbIB("BPIC13_open_8", ev, pn)
    _,_ = sbib.compute_smcABC(N=50, initial_threshold=0.99, threshold_tolerance=0.0025, fixed_w={}, njob=8, v=0)

    ev = EventLog("rl_data/BPIC20_dd/BPIC20_dd.xes")
    pn = ev.discover_pn_inductive()
    sbib = SbIB("BPIC20_dd_8", ev, pn)
    _,_ = sbib.compute_smcABC(N=50, initial_threshold=0.99, threshold_tolerance=0.0025, fixed_w={}, njob=8, v=0)

    ev = EventLog("rl_data/roadfines/roadfines.xes")
    pn = ev.discover_pn_inductive()
    sbib = SbIB("roadfines_8", ev, pn)
    _,_ = sbib.compute_smcABC(N=50, initial_threshold=0.99, threshold_tolerance=0.0025, fixed_w={}, njob=8, v=0)