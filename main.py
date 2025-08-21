import warnings

from Optimizer_SPN.unfolding_based_opt import UbOPT
from log.Eventlog import Eventlog


def xp_UbOPT(filename):

    ev = Eventlog(filename)
    pn = ev.discover_pn_inductive()
    ubopt = UbOPT(ev, pn)

    # L-BFGS-B, TNC, Powell, Nelder-Mead
    result = ubopt.estimate(obj_function="KLD", method="L-BFGS-B", nw0=100, memoized=True, derivatives=False)
    print(result)

if __name__ == '__main__':
    warnings.filterwarnings("ignore")
    xp_UbOPT("rl_data/BPIC13_open/BPIC13_open.xes")
