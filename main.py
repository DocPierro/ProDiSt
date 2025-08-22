import time
import random
import warnings

from Optimizer_SPN.unfolding_based_opt import UbOPT
from Optimizer_SPN.simulation_based_InfBayes import SbIB
from Optimizer_SPT.spt_opt import SPT_OPT
from sim.Cosmos import Cosmos
from log.Eventlog import EventLog


def xp_SPTOPT(filename):

    ev = EventLog(filename)
    pt = ev.discover_pt_inductive()
    spt_opt = SPT_OPT(ev,pt)

    optimized_spt, opt_prob = spt_opt.estimate_sim(obj_function="rEMD", method="Powell", n=10000, starting_prob=None, nw0=10)

def xp_SbIB(filename):

    ev = EventLog(filename)
    pn = ev.discover_pn_inductive()
    sbib = SbIB("test_sbib", ev, pn)

    optimized_spn, opt_w = sbib.compute_smcABC(N=50, initial_threshold=0.99, threshold_tolerance=0.01, fixed_w={}, njob=16, v=0)

def xp_Cosmos(filename):

    ev = EventLog(filename)
    pn = ev.discover_pn_inductive()
    cosmos = Cosmos("test_cosmos", ev, pn)

    start_time = time.time()
    weights = {transition.get_name(): random.random() for transition in pn.get_transitions()}
    nr, pn_language = cosmos.simulate(weights, level=0.99, width=0.001)

    print("Simulated restricted stochastic language : " + str(pn_language))
    print("Number of Runs: " + str(nr))
    print("Execution Time: " + str(time.time() - start_time) + " seconds")

def xp_UbOPT(filename):

    ev = EventLog(filename)
    pn = ev.discover_pn_inductive()
    ubopt = UbOPT(ev, pn)

    optimized_spn, opt_w = ubopt.estimate(obj_function="KLD", method="L-BFGS-B", nw0=100, memoized=False, derivatives=False)

if __name__ == '__main__':
    warnings.filterwarnings("ignore")
    #xp_UbOPT("rl_data/BPIC13_open/BPIC13_open.xes")
    #xp_Cosmos("rl_data/BPIC13_open/BPIC13_open.xes")
    #xp_SbIB("rl_data/BPIC13_open/BPIC13_open.xes")
    #xp_SPTOPT("rl_data/BPIC13_open/BPIC13_open.xes")
