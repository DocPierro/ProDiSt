import os
import sys
import time
import numpy
import shutil
import random
import statistics
import numpy as np
import multiprocessing
from colorama import Fore
import matplotlib.pyplot as plt
from datetime import datetime as dt
from scipy.stats import multivariate_normal
from sklearn.neighbors import KernelDensity

from Optimizer_SPN.unfolding_based_opt import UbOPT
from Levenshtein import distance as levenshtein_distance
from pm4py.algo.evaluation.earth_mover_distance.variants import pyemd

from Optimizer_SPN.minimax_tilting_sampler import TruncatedMVN


class SbIB:

    def __init__(self, name, ev, pn):
        self.name, self.ev, self.pn = "xp/" + name, ev, pn
        self.ev_language = self.ev.get_language_pm4py()
        self.weight_dir = self.name + "/Weight"
        self.result_dir = self.name + "/Result"
        self.plot_dir = self.name + "/Plot"

        if os.path.exists(self.name):
            shutil.rmtree(self.name)
        os.mkdir(self.name)
        os.mkdir(self.weight_dir)
        os.mkdir(self.result_dir)
        os.mkdir(self.plot_dir)

        with open(self.name + "/gspn1.gspn", "w") as file:
            file.write(self.pn.gen_gspn())
        with open(self.name + "/lha1.lha", "w") as file:
            file.write(self.ev.gen_lha(pn))

    ###################################################################################################################
    ###################################################################################################################
    ###################################################################################################################

    def emd_normalized_levenshtein(self, pn_language):
        distance = numpy.zeros((len(self.ev_language), len(pn_language)))
        for x, t1 in enumerate(self.ev_language):
            for y, t2 in enumerate(pn_language):
                if len(t1) == 0 or len(t2) == 0:
                    distance[x, y] = 1.
                else:
                    distance[x, y] = float(levenshtein_distance(t1, t2)) / float(max(len(t1), len(t2)))
        return pyemd.emd(numpy.array([self.ev_language[t1] for t1 in self.ev_language]),
                         numpy.array([pn_language[t1] for t1 in pn_language]),
                         distance)

    ###################################################################################################################
    ###################################################################################################################
    ###################################################################################################################

    def read_result(self, t, n):
        ev_language, pn_language, = self.ev.get_language(), {}
        with open(self.result_dir + "/result_" + str(t) + "_" + str(n) + ".res", "r") as file:
            id = 0
            for line in file.readlines():
                if line[:16] == "Estimated value:":
                    pn_language[ev_language[id].get_seq()] = float(line[16:])
                    id += 1
        return pn_language

    def write_weight(self, t, n, particle):
        with open(self.weight_dir + "/weights_" + str(t) + "_" + str(n) + ".txt", "w") as file:
            for weight in particle:
                file.write("w_" + weight + ":" + str(particle[weight]) + "\n")

    ###################################################################################################################
    ###################################################################################################################
    ###################################################################################################################

    def kde(self, particles):
        sample = []
        for particle in particles:
            sample.append(list(particle["theta"].values()))
        X = np.array(sample)
        kde = KernelDensity(kernel='gaussian', bandwidth=0.2).fit(X)
        kde_samples = kde.sample(1000)
        i = 0
        for transition in self.pn.get_transitions():
            fig_kde = plt.figure()
            y, x, _ = plt.hist(kde_samples[:, i], bins=100)
            plt.title("KDE -> " + str(transition.get_name()))
            plt.savefig(self.plot_dir + transition.get_name() + "_KDE")
            plt.close(fig_kde)
            i+=1

    ###################################################################################################################
    ###################################################################################################################
    ###################################################################################################################

    def print_particle(self, accepted, t, n, s, particle, ev_language, pn_language, dist, v):
        if accepted:
            if v >= 3:
                print(Fore.GREEN + "####################################################################################################")
            if v >= 2:
                print(Fore.GREEN + "### ACCEPTED: [t = " + str(t) + "; n = " + str(n) + "; Simulation = " + str(s) + "] -> " + str(dist) + " ###")
            if v >= 3:
                print(Fore.GREEN + "theta:" + str(particle))
                print("Log Language: " + str(ev_language))
                print("Net Language: " + str(pn_language))
                print("emd: " + str(dist))
                print("####################################################################################################")
                print(Fore.RESET)
        else:
            if v >= 3:
                print(Fore.RED + "####################################################################################################")
            if v >= 2:
                print(Fore.RED + "### REJECTED: [t = " + str(t) + "; n = " + str(n) + "; Simulation = " + str(s) + "] -> " + str(dist) + " ###")
            if v >= 3:
                print(Fore.RED + "w: " + str(particle))
                print("Log Language: " + str(ev_language))
                print("Net Language: " + str(pn_language))
                print("emd: " + str(dist))
                print("####################################################################################################")
                print(Fore.RESET)

    def print_particles(self, particles, threshold, njob):
        print(Fore.BLUE + "####################################################################################################")
        print("ABC[t=" + str(particles["t"]) + ";N=" + str(len(particles["particles"])) + ";threshold=" + str(threshold) + ";njob=" + str(njob) + "] in " + dt.strftime(dt.utcfromtimestamp(particles["execution_time"]), '%H:%M:%S') + ":")
        for n, particle in enumerate(particles["particles"]):
            print("\t" + str(n+1) + ". " + str(particle))
        print(Fore.BLUE + "####################################################################################################")
        print(Fore.RESET)

    def plot_particles(self, particles, threshold, njob):
        weights_sol = {}
        for transition in self.pn.get_transitions():
            sample = []
            for n, particle in enumerate(particles["particles"]):
                sample.append(particle["theta"][transition.get_name()])
            fig_hist = plt.figure()
            y, x, _ = plt.hist(sample, bins=100, color=(0, 128/255, 122/255))
            plt.title(r"$\mathrm{ABC}[t=" + str(particles["t"]) + r";\,N=" + str(len(particles["particles"])) + r";\,\mathrm{threshold}=" + f"{threshold:.5f}" + r";\,njob=" + str(njob) + r"]\ \mathrm{in}\ " + dt.strftime(dt.utcfromtimestamp(particles["execution_time"]), '%H\!:\!%M\!:\!%S') + r"$")
            plt.savefig(self.plot_dir + "/t" + str(particles["t"]) + "_" + transition.get_name() + ".pdf")
            plt.close(fig_hist)
            weights_sol[transition.get_name()] = x[np.where(y == y.max())][0]
        return weights_sol

    def export_particles(self, result, njob):
        with open(self.name + "/particles.res", "w") as file:
            for res in result:
                file.write("ABC[t=" + str(res["t"]) + ";N=" + str(res["N"]) + ";threshold=" + str(res["threshold"]) + ";njob=" + str(njob) + "] in " + dt.strftime(dt.utcfromtimestamp(res["execution_time"]), '%H:%M:%S') + ":\n")
                for n, particle in enumerate(res["particles"]):
                    file.write("\t" + str(n + 1) + ". " + str(particle) + "\n")
                file.write("\n")

    def export_results(self, N, threshold_tolerance, result, sol, weighted_mean, median, elapsed, njob):
        ubopt = UbOPT(self.ev, self.pn)
        with open(self.name + "/results.res", "w") as file:
            file.write(self.name + " with inductive\n\n")
            file.write("\tM: " + str(len(result)) + " | N: " + str(N) + " | threshold_tolerance: " + str(threshold_tolerance) + "\n")
            file.write("\tThresholds: " + str([layer["threshold"] for layer in result]) + "\n\n")
            file.write("\trEMD_best: " + str(self.emd_normalized_levenshtein(ubopt.unfold_rg(list(sol[-1]["weights"].values())))) + "\n")
            file.write("\trEMD_weighted_mean: " + str(self.emd_normalized_levenshtein(ubopt.unfold_rg(weighted_mean))) + "\n")
            file.write("\trEMD_median: " + str(self.emd_normalized_levenshtein(ubopt.unfold_rg(median))) + "\n\n")
            file.write("\tComputation time: " + str(elapsed) + " seconds | " + dt.strftime(dt.utcfromtimestamp(elapsed),'%H:%M:%S') + " | (njob:" + str(njob) + ")")

    ###################################################################################################################
    ###################################################################################################################
    ###################################################################################################################

    def get_multivariate_normal_sample(self, mean, cov):
        tmvn = TruncatedMVN(np.array(mean), cov, np.zeros(len(mean)), np.ones(len(mean)))
        sample = [i for ii in tmvn.sample(1).tolist() for i in ii]
        return sample

    def random_uniform_sim(self, param):

        s = 0
        n, threshold, fixed_w, v = param
        ev_language = self.ev.get_language()

        while True:

            s += 1
            particle = {"theta": ({transition.get_name(): (random.random()) if not (transition.get_name() in fixed_w) else fixed_w[transition.get_name()]
                                   for transition in self.pn.get_transitions()})}
            self.write_weight(0, n, particle["theta"])

            os.system("Cosmos/bin/Cosmos " + self.name + "/gspn1.gspn " + self.name + "/lha1.lha --tmp-path " + self.name + " --tmp-status reuse --width 0.1 --weight-param " + self.weight_dir + "/weights_0_" + str(n) + ".txt --output-result-name " + self.result_dir + "/result_0_" + str(n) + " -v 0")
            pn_language = self.read_result(0, n)

            dist_emd = self.emd_normalized_levenshtein(pn_language)
            if dist_emd < threshold:
                self.print_particle(True, 0, n, s, particle, ev_language, pn_language, dist_emd, v)
                particle["weight"] = 1
                particle["dist"] = dist_emd
                return particle
            else:
                self.print_particle(False, 0, n, s, particle, ev_language, pn_language, dist_emd, v)

    def random_multivariate_sim(self, param):

        s = 0
        t, n, old_particles, threshold, fixed_w, v = param
        ev_language = self.ev.get_language()

        while True:

            s += 1
            old_particle = random.choices([old_particle["theta"] for old_particle in old_particles],[old_particle["weight"] for old_particle in old_particles], k=1)[0]
            mean = list(old_particle.values())
            cov = np.cov([[list((particle["theta"]).values())[d] for particle in old_particles] for d in range(len(mean))])
            sample = self.get_multivariate_normal_sample(mean, cov)
            new_particle = {"theta": ({transition.get_name(): sample[i] if not (transition.get_name() in fixed_w) else fixed_w[transition.get_name()]
                                       for i, transition in enumerate(self.pn.get_transitions())})}
            self.write_weight(t, n, new_particle["theta"])

            os.system("Cosmos/bin/Cosmos " + self.name + "/gspn1.gspn " + self.name + "/lha1.lha --tmp-path " + self.name + " --tmp-status reuse --width 0.1 --weight-param " + self.weight_dir + "/weights_" + str(t) + "_" + str(n) + ".txt --output-result-name " + self.result_dir + "/result_" + str(t) + "_" + str(n) + " -v 0")
            pn_language = self.read_result(t, n)

            dist_emd = self.emd_normalized_levenshtein(pn_language)
            if dist_emd < threshold:
                self.print_particle(True, t, n, s, new_particle, ev_language, pn_language, dist_emd, v)
                var = multivariate_normal(mean, cov, allow_singular=True)
                new_particle["weight"] = 1/np.sum([old_particle["weight"]*var.pdf(list(old_particle["theta"].values()))
                                                   for old_particle in old_particles])
                new_particle["dist"] = dist_emd
                return new_particle
            else:
                self.print_particle(False, t, n, s, new_particle, ev_language, pn_language, dist_emd, v)

    ###################################################################################################################
    ###################################################################################################################
    ###################################################################################################################

    def compute_smcABC(self, N=100, initial_threshold=0.98, threshold_tolerance=0.0025, fixed_w={}, njob=1, v=0):
        sys.setrecursionlimit(80000)

        start = time.time()
        t, result, sol = 0, [], []
        os.system("Cosmos/bin/Cosmos " + self.name + "/gspn1.gspn " + self.name + "/lha1.lha --tmp-path " + self.name + " --tmp-status keep --max-run 0 -v 0")

        multiprocessing.set_start_method('spawn', force=True)
        with (multiprocessing.get_context("spawn").Pool(njob) as pool):
            while True:
                if t == 0:
                    threshold = initial_threshold
                    print("##### Layer " + str(t), " with threshold: " + str(threshold) + " #####")
                    if njob > 1:
                        particles = pool.map(self.random_uniform_sim, zip(range(1, N+1), [threshold] * N, [fixed_w] * N, [v] * N))
                    else:
                        particles = [self.random_uniform_sim([n+1, threshold, fixed_w, v]) for n in range(N)]
                else:
                    threshold = result[t-1]["emd_median"]
                    print("##### Layer " + str(t), " with threshold: " + str(threshold) + " #####")
                    if njob > 1:
                        particles = pool.map(self.random_multivariate_sim, zip([t] * N, range(1, N+1), [result[t-1]["particles"]] * N, [threshold] * N, [fixed_w] * N, [v] * N))
                    else:
                        particles = [self.random_multivariate_sim([t, n+1, result[t-1]["particles"], threshold, fixed_w, v]) for n in range(N)]

                    weights = [particle["weight"] for particle in particles]
                    for particle in particles:
                        particle["weight"] = particle["weight"]/np.sum(weights)

                emd_median = statistics.median([particle["dist"] for particle in particles])

                elapsed_t = time.time() - start
                #self.kde(particles)
                result.append({"t": t, "particles": particles, "execution_time": elapsed_t, "N":N, "threshold": threshold, "emd_median": emd_median})
                sol.append({"t": t, "weights": self.plot_particles(result[t], threshold, njob)})
                if v >= 1:
                    self.print_particles(result[t], threshold, njob)

                print("threshold_evolution: " + str(abs(result[t]["threshold"] - result[t]["emd_median"])))
                if t != 0 and abs(result[t]["threshold"] - result[t]["emd_median"]) < threshold_tolerance:
                    break
                t+=1

        weighted_mean, median = {}, {}
        for transition in self.pn.get_transitions():
            weighted_mean[transition.get_name()] = np.average(([particle['theta'][transition.get_name()] for particle in result[-1]["particles"]]),
                                                                    weights=[particle['weight'] for particle in result[-1]["particles"]])
            median[transition.get_name()] = np.median([particle['theta'][transition.get_name()] for particle in result[-1]["particles"]])

        elapsed = (time.time() - start)

        self.export_particles(result, njob)
        self.export_results(N, threshold_tolerance, result, sol, weighted_mean, median, elapsed, njob)

        self.pn.set_weights(sol[-1]["weights"])
        return self.pn, sol[-1]["weights"]
