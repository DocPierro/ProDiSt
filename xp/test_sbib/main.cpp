#include "BatchR.hpp"
#include "clientsim.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
int main(int argc, char** argv) {
    signal(SIGHUP, signalHandler);
    signal(SIGINT, signalHandler);
    {const string tmppath(argv[1]);
    ifstream ifs(tmppath+"/parameters.txt");
    readParameters(ifs);}
    SPN_orig<EventsQueue> N(0);
    fstream weight_file;
    weight_file.open (P.weight_file,ios::in);
    if (weight_file.is_open()) {
        string line;
        while (getline(weight_file, line)) {
            string name = line.substr(0,line.find(':'));
            double val = stod(line.substr(line.find(":")+1,line.size()));
            N.overrideParameter(name,val);
        }
    }
    LHA_orig<typename decltype(N)::stateType> A;
    Simulator<EventsQueue,typeof N> sim(N,A);
    bool singleBatch = false;
    sim.SetBatchSize(1000);
    setSimulator(sim,argc,argv,P);
    if((P.verbose>=4)|singleBatch)sim.RunBatch();
    else while( !cin.eof() && P.graceFullEnding <= 1 ){
        BatchR batchResult = sim.RunBatch(); //simulate a batch of trajectory
        batchResult.outputR(cout); // output the result on the standart output
    }
    return (EXIT_SUCCESS);
}

