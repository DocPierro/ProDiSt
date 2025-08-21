import time
import random
import warnings

from datetime import datetime as dt

from Optimizer_SPN.unfolding_based_opt import UbOPT
from Optimizer_SPN.simulation_based_InfBayes import SbIB
from sim.Cosmos import Cosmos
from log.Eventlog import Eventlog


def xp_SbIB(filename):

    ev = Eventlog(filename)
    pn = ev.discover_pn_inductive()
    sbib = SbIB("test_sbib", ev, pn)

    result, sol, weighted_mean, median, elapsed = sbib.compute_smcABC(N=50, initial_threshold=0.99, threshold_tolerance=0.01, fixed_w={}, njob=16, v=0)
    print("Computation time: " + str(elapsed) + " seconds | " + dt.strftime(dt.utcfromtimestamp(elapsed),'%H:%M:%S') + " | (njob:" + str(16) + ")")

def xp_Cosmos(filename):

    ev = Eventlog(filename)
    pn = ev.discover_pn_inductive()
    cosmos = Cosmos("test_cosmos", ev, pn)

    start_time = time.time()
    weights = {transition.get_name(): random.random() for transition in pn.get_transitions()}
    nr, pn_language = cosmos.simulate(weights, level=0.99, width=0.001)

    print("Simulated restricted stochastic language : " + str(pn_language))
    print("Number of Runs: " + str(nr))
    print("Execution Time: " + str(time.time() - start_time) + " seconds")

def xp_UbOPT(filename):

    ev = Eventlog(filename)
    pn = ev.discover_pn_inductive()
    ubopt = UbOPT(ev, pn)

    # L-BFGS-B, TNC, Powell, Nelder-Mead
    result = ubopt.estimate(obj_function="KLD", method="L-BFGS-B", nw0=100, memoized=False, derivatives=False)
    print(result)

if __name__ == '__main__':
    warnings.filterwarnings("ignore")
    #xp_UbOPT("rl_data/BPIC13_open/BPIC13_open.xes")
    #xp_Cosmos("rl_data/BPIC13_open/BPIC13_open.xes")
    sbib = xp_SbIB("rl_data/BPIC13_open/BPIC13_open.xes")
