//
// Created by Timofey Dankevich on 29/12/2020.
//

#ifndef RELIABILITY_HAKATON_MONTECARLO_H
#define RELIABILITY_HAKATON_MONTECARLO_H
#include "Graph.h"

class MonteCarlo {
public:
    static void toSetStateOfEdges(vector<double>& stateOfEdges, const vector<double>& permutation);
    static void toChangeStateOfGraph(Graph& graph, const vector<double>& stateOfEdges);
    static int computeReliability(Graph& graph, double& M, const vector<double>& permutation, int& T1, int& T2, int& T3);
};


#endif //RELIABILITY_HACKATHON_MONTECARLO_H
