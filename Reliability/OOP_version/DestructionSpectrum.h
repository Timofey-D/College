//
// Created by Timofey Dankevich on 17/12/2020.
//

#ifndef RELIABILITY_NETWORK_DESTRUCTIONSPECTRUM_H
#define RELIABILITY_NETWORK_DESTRUCTIONSPECTRUM_H
#include <Graph.h>

class DestructionSpectrum {
public:
    static vector<double> getDestroySystem(Graph& graph, const double& M, const int& T1, const int& T2, const int& T3);
    static int getCumulativeSpectrum(Graph& graph, vector<int>& turnOff, const int& T1, const int& T2, const int& T3);
    static void createPermutationEdges(double* start, int length);
    static void statisticDestroySystem(vector<double>& destroySystem, const int& M);
    static vector<double> createFVector(const double& p, const int& numberOfEdges);
    static double getPF(const vector<double>& F, const vector<double>& destroySystem);
    static vector<double> cumulativeVector(vector<double>& destroySystem);
};

#endif //RELIABILITY_NETWORK_DESTRUCTIONSPECTRUM_H
