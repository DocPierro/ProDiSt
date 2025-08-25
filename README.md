# ProDiSt - A Tool for Process Discovery by Stochastic approaches

**ProDiSt** is a Python 3 research tool for **stochastic process discovery**. It provides methods to automatically discover stochastic models, such as **stochastic workflow nets (sWNs)** and **stochastic process trees (sPTs)**, from event logs, capturing both the **structural behavior** and the **probabilistic information** contained in real-world processes.

More information: [ProDiSt WebSite](https://pierrecry98.github.io/tool.html)

## 📦 Installation

1. Clone the repository:
  ```
  git clone https://github.com/DocPierro/ProDiSt
  cd ProDiSt
  ```

2. Create a virtual environment and install dependencies (choose one of the two options):
  - Using Python ```venv```:
    ```
    python3 -m venv venv
    source venv/bin/activate
    
    pip install --upgrade pip
    pip install -r requirements.txt
    ```
  - Using Anaconda / Miniconda:
    ```
    conda create -n prodist python=3.9
    conda activate prodist
    
    pip install --upgrade pip
    pip install -r requirements.txt
    ```

3. (Optional) Build COSMOS (needed for simulation-based Bayesian inference):\
   More information here: https://cosmos.lacl.fr/
   
   1. Install COSMOS Dependancy:
      - A C++ compiler (g++ or clang++).
      - The development version of the expat library (```libexpat-dev``` or ```libexpat1-dev```).
      - The development version of the boost library (```libboost-dev```).
      - Bison and Flex parser and lexer generator.
      - The development version of the zip library (```libz-dev```).
      - The OCaml Compiler version ≥ 4.08.1 with libraries ```camlzip```, ```xml-light```, ```ocamlfind```, ```camlp4```, ```ocamlbuild```.\
        This can easily be installed with opam using the command line:
        ```
        opam init --comp 4.08.1; opam update; eval `opam config env`; opam install camlzip xml-light ocamlfind camlp4 ocamlbuild
        ```
        On Debian, you can install all the dependencies with:
          ```
          apt-get install -y g++ gnuplot libexpat-dev libboost-dev libz-dev bison flex
          ```
        Note that on macOS, all the dependencies can be installed with brew after installing XCode.

    2. Compile COSMOS and generate the executable:
       ```
       ./configure
       make
       make install
       ```
## 🚀 Usage

### Example 1 - Import an event log and discover a Petri Net and Process Tree
```python
from log.Eventlog import EventLog

# Load an event log (XES file)
filename = "toy_data/ex1.xes"
ev = EventLog(filename)

# Discover a Petri net using the inductive miner
pn = ev.discover_pn_inductive()

# Discover a Process tree using the inductive miner
pt = ev.discover_pt_inductive()
```

### Example 2 - Discover a stochastic Petri net using the log-driven unfolding-based optimization framework

```python
from log.Eventlog import EventLog
from Optimizer_SPN.unfolding_based_opt import UbOPT

# Load an event log (XES file)
filename = "rl_data/BPIC13_closed.xes"
ev = EventLog(filename)

# Discover a Petri net using the inductive miner
pn = ev.discover_pn_inductive()

# Initialize the unfolding-based optimizer
ubopt = UbOPT(ev, pn)

# Estimate optimal parameters with unfolding-based optimization
optimized_spn, opt_w = ubopt.estimate(
    obj_function="KLD",
    method="L-BFGS-B",
    nw0=100,
    memoized=False,
    derivatives=False
)

print("Optimized Petri Net:", optimized_spn)
print("Optimal weights:", opt_w)
```

## 📂 Repository Structure

```
ProDiSt/
│── log/                                # Event log library
│ ├── Eventlog.py                       # Event, Trace and EventLog classes
│ ├── init.py
│ ├── log_test.py
│
│── model/                              # Process model library
│ ├── Petrinet.py                       # Place, Transition, Arc and StochasticPetriNet classes
│ ├── Processtree.py                    # Seq, Choice, Parallel, Loop and StochasticProcessTree classes
│ ├── init.py
│ ├── model_test.py
│
│── optimizer_spn/                      # Optimization for stochastic Petri nets
│ ├── minimax_tilting_sampler.py        # Multivariate truncated Gaussian sampler [4]
│ ├── unfolding_based_opt.py            # UbOPT: exact unfolding-based optimization [1]
│ ├── simulation_based_InfBayes.py      # SbIB: Bayesian inference of sWN parameters [2]
│
│── optimizer_spt/                      # Optimization for stochastic process trees
│ ├── spt_opt.py                        # SPT_OPT: optimization of sPT parameters [3]
│
│── cosmos/                             # COSMOS model checker (source, build, executables)
│── xp/                                 # Directory for COSMOS simulation files
│
│── toy_data/                           # Synthetic and toy event logs
│── rl_data/                            # Real-life logs (e.g. BPI Challenge)
│── rl_data.zip                         # Zipped version of real-life logs
│
│── main.py
│── requirements.txt
│── LICENSE
│── README.md
```

## 📖 Documentation

For theoretical background and details on the methods implemented in **ProDiSt**, you can refer to the following research papers:

[1]. Cry, P., Horváth, A., Ballarini, P., & Le Gall, P. (2024).\
   *A Framework for Optimisation-Based Stochastic Process Discovery.*\
   In: Hillston, J., Soudjani, S., & Waga, M. (eds) Quantitative Evaluation of Systems and Formal Modeling and Analysis of Timed Systems (QEST+FORMATS 2024).\
   Lecture Notes in Computer Science, vol. 14996. Springer, Cham.\
   [https://doi.org/10.1007/978-3-031-68416-6_3](https://doi.org/10.1007/978-3-031-68416-6_3)

[2]. Pierre Cry, Paolo Ballarini, András Horváth, Pascale Le Gall.\
    *Statistical Bayesian Inference for Stochastic Process Discovery.*\
    International Conference on Quantitative Evaluation of SysTems (QEST),\
    Aug 2025, Aarhus (Danemark), Denmark.\
    [hal-05134848](https://hal.science/hal-05134848v1)

[3]. Horváth, A., Ballarini, P., & Cry, P. (2025).\
   *Probabilistic Process Discovery with Stochastic Process Trees.*\
   arXiv preprint.\
   [https://arxiv.org/abs/2504.05765](https://arxiv.org/abs/2504.05765)

### Additional References

ProDiSt also makes use of existing work on multivariate truncated Gaussian distributions:

[4]. Botev, Z. I. (2016).\
     *The normal law under linear restrictions: simulation and estimation via minimax tilting.*\
     Journal of the Royal Statistical Society: Series B (Statistical Methodology), 79(1), 125–148.\
     [https://doi.org/10.1111/rssb.12162](https://doi.org/10.1111/rssb.12162)

## 🔬 Research Context
ProDiSt is developed as part of a Ph.D. project in collaboration between the **MICS Laboratory at CentraleSupélec, University of Paris-Saclay** and the **Computer Science Department of the University of Turin**.
The tool is intended for **research and academic purposes** in the field of **process mining** and **stochastic process discovery**.

## 📜 License
ProDiSt is licensed under the [Apache License 2.0](LICENSE).\
You may not use this project except in compliance with the License.\
A copy of the License is provided in the repository and is also available at [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)

## 📬 Contact
- **Maintainer:** Pierre Cry  
  - 🌐 Website: [https://pierrecry98.github.io](https://pierrecry98.github.io)  
  - 📧 Email: pierre.cry@centralesupelec.fr

