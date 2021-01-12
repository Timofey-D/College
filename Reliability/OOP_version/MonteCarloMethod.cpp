//
// Created by Timofey Dankevich on 17/12/2020.
//

#include "MonteCarloMethod.h"
#include <Random.h>
#include <Graph.h>
#include <array>
#include <main.h>

void MonteCarloMethod::fillRandomStateArray(double * array, int& length) {
    for (int pos = 0; pos < length; pos++)
        array[pos] = Random::randomNumber();
}

void MonteCarloMethod::changingConnection(Graph& graph, double * array, int length, double& P) {
    int numberOfEdge = 1;
    for (int pos = 0; pos < length; pos++) {
        if (array[pos] > P) {
            numberOfEdge += pos;
            graph.removeConnection(numberOfEdge);
            numberOfEdge = 1;
        }
    }
}

int MonteCarloMethod::computeReliability(Graph& graph, int& M, double& P, int& T1, int& T2, int& T3) {
    array<double, 30> randomState {};
    int lengthRandomState = randomState.size();
    int R = 0;  // Reliability network
    for (int round = 1; round <= M; round++) {
        randomState.fill(0);
        fillRandomStateArray(randomState.begin(), lengthRandomState);
        changingConnection(graph, randomState.begin(), randomState.size(), P);
        graph.findPath(T1);
        if (graph.checkNode(T2) && graph.checkNode(T3))
            R++;
        graph.clearVisit();
        graph.removeAllConnection();
        main::createConnection(graph);
    }
    return R;
}