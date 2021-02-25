#include "Graph.h"
#include "MonteCarlo.h"
#include <iostream>
#include "Random.h"
#include <vector>
#include "Utility.h"
using namespace std;

void createConnection(Graph& graph) {
    graph.removeAllConnection();
    graph.addConnection(1, 2, 1);
    graph.addConnection(2, 3, 2);
    graph.addConnection(1, 4, 3);
    graph.addConnection(3, 4, 4);
    graph.addConnection(2, 6, 5);
    graph.addConnection(2, 5, 6);
    graph.addConnection(3, 5, 7);
    graph.addConnection(4, 5, 8);
    graph.addConnection(1, 3, 9);
    graph.addConnection(4, 6, 10);
}

__unused void permutationVector(vector<double>& permutation) {
    int length = permutation.size();
    for (int i = 0; i < length; ++i) {
        int position = Random::randomInteger(0, 9);
        double change = permutation[i];
        permutation[i] = permutation[position];
        permutation[position] = change;
    }
}

void computeReliabilityNetwork(Graph& graph, int& T1, int& T2, int& T3) {
    vector<double> permutation = {0.3, 0.95, 0.4, 0.5, 0.9, 0.6, 0.1, 0.2, 0.8, 0.7};
    double M = 10000;
    int loop = 1;
    cout << "Terminals:\n" << "T1 = " << T1 <<
    endl << "T2 = " << T2 << endl << "T3 = " << T3 <<
    endl << "M = " << M << endl << "Permutation: ";
    Utility::showVector(permutation);
    while (loop <= 10) {
        int R = MonteCarlo::computeReliability(graph, M, permutation, T1, T2, T3);
        cout << "R/M: " << ((double) R / (double) M) << endl;
        loop++;
    }
}

int main() {
    int T1 = 3;
    int T2 = 6;
    int T3 = 2;
    Graph graph = Graph(6, 10);
    createConnection(graph);
    cout << "The connections are in the graph:" << endl;
    graph.showMatrix();
    computeReliabilityNetwork(graph, T1, T2, T3);
    return 0;
}
