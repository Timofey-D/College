//
// Created by Timofey Dankevich on 29/12/2020.
//

#include "MonteCarlo.h"
#include "MonteCarlo.h"
#include "Random.h"
#include "Graph.h"
#include <array>
#include "main.h"
#include "Utility.h"

#include <iostream>
using namespace std;

void MonteCarlo::toSetStateOfEdges(vector<double>& stateOfEdges, const vector<double>& permutation) {
    int numberOfEdges = stateOfEdges.size();
    for (int pos = 0; pos < numberOfEdges; pos++) {
        double randomValue = Random::randomNumber();
        if (randomValue <= permutation[pos])
            stateOfEdges[pos] = 1;
        else
            stateOfEdges[pos] = 0;
    }
}

void MonteCarlo::toChangeStateOfGraph(Graph& graph, const vector<double>& stateOfEdges) {
    int numberOfEdges = graph.getE();
    for (int pos = 0; pos < numberOfEdges; pos++) {
        if (stateOfEdges[pos] == 0) {
            graph.removeConnection(pos + 1);
        }
    }
}

int MonteCarlo::computeReliability(Graph& graph, double& M, const vector<double>& permutation, int& T1, int& T2, int& T3) {
    vector<double> stateOfEdges(graph.getE());
    int R = 0;  // Reliability network
    for (int round = 1; round <= M; round++) {
        // To recover the state of edges and setting new state of edges
        Utility::getCleanVector(stateOfEdges, 0);
        toSetStateOfEdges(stateOfEdges, permutation);
        toChangeStateOfGraph(graph, stateOfEdges);
        // to go round the graph and to find a path between terminals
        graph.DFS(T1);
        if (graph.checkNode(T1) && graph.checkNode(T2) && graph.checkNode(T3)) {
            R++;
//            cout << endl;
//            graph.showVisited();
//            cout << endl;
        }
        // To recover the graph before next iteration
        graph.clearVisit();
        createConnection(graph);
    }
    return R;
}
