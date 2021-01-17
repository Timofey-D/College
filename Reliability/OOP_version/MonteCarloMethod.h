//
// Created by Timofey Dankevich on 17/12/2020.
//

#ifndef RELIABILITY_NETWORK_MONTECARLOMETHOD_H
#define RELIABILITY_NETWORK_MONTECARLOMETHOD_H
#include <Graph.h>

class MonteCarloMethod {
public:
    static void fillRandomStateArray(double * array, int& length);
    static void changingConnection(Graph& graph, const double * array, int length, double& P);
    static int computeReliabilityDependsOnP(Graph& graph, int& M, double& P, int& T1, int& T2, int& T3);
    static int computeReliability(Graph& graph, int edge, int stateEdge, double P, int& M, int& T1, int& T2, int& T3);
    static int computeReliabilityExperiment(Graph& graph, int& M, double& P, int& T1, int& T2, int& T3);
};


#endif //RELIABILITY_NETWORK_MONTECARLOMETHOD_H
