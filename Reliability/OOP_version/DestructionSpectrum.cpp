//
// Created by Timofey Dankevich on 17/12/2020.
//

#include "DestructionSpectrum.h"
#include "Random.h"
#include "main.h"
#include <Utilities.h>
#include <Statistic.h>
using namespace std;


vector<double> DestructionSpectrum::cumulativeVector(vector<double> & destroySystem) {
    for (int pos = 0; pos < destroySystem.size(); pos++) {
        if (pos - 1 >= 0 /*&& destroySystem[pos] != 0*/)
            destroySystem[pos] = destroySystem[pos] + destroySystem[pos - 1];
    }
    return destroySystem;
}


double DestructionSpectrum::getPF(const vector<double>& F, const vector<double>& destroySystem) {
    double result = 0;
    for (int index = 0; index < F.size(); index++)
        result += destroySystem[index] * F[index];
    return result;
}


vector<double> DestructionSpectrum::createFVector(const double& p, const int& numberOfEdges) {
    vector<double> F(numberOfEdges, 0);
    Utilities::nullifyVector(F);
    for (int edge = 0; edge < F.size(); edge++) {
        for (int loop = edge + 1; loop <= numberOfEdges; loop++) {
            F[edge] += (Statistic::permutation(numberOfEdges, loop) *
                    pow(1 - p, loop) *
                    pow(p, numberOfEdges - loop));
        }
    }
    return F;
}


vector<double> DestructionSpectrum::getDestroySystem(Graph& graph, const double& M, const int& T1, const int& T2, const int& T3) {
    vector<double> destroySystem;
    destroySystem.resize(graph.getE());
    double permutationEdges[graph.getE()];
    Utilities::nullifyVector(destroySystem);
    for (int m = 1; m <= M; m++) {
        Utilities::nullifyArray(permutationEdges, graph.getE());
        createPermutationEdges(permutationEdges, graph.getE());
        graph.removeAllConnection();
        main::createConnection(graph);
        for (int index = 0; index < graph.getE(); index++) {
            graph.removeConnection(permutationEdges[index]);
            permutationEdges[index] = 0;
            graph.clearVisit();
            graph.findPath(T1);
            if (!graph.checkNode(T2) || !graph.checkNode(T3)) {
                destroySystem[index]++;
                break;
            }
        }
    }
    return destroySystem;
}


int DestructionSpectrum::getCumulativeSpectrum(Graph &graph, vector<int>& turnOff, const int &T1, const int &T2, const int &T3) {
    vector<double> destroySystem(graph.getE(), 0);
    destroySystem.resize(graph.getE());
    double permutationEdges[graph.getE()];
    Utilities::nullifyArray(permutationEdges, graph.getE());
    createPermutationEdges(permutationEdges, graph.getE());
    graph.removeAllConnection();
    main::createConnection(graph);
    for (int index = 0; index < graph.getE(); index++) {
        turnOff[permutationEdges[index] - 1]++;
        graph.removeConnection(permutationEdges[index]);
        permutationEdges[index] = 0;
        graph.clearVisit();
        graph.findPath(T1);
        if (!graph.checkNode(T2) || !graph.checkNode(T3)) {
            return index + 1;
        }
    }
//    return destroySystem;
}


void DestructionSpectrum::createPermutationEdges(double* start, int length) {
    int random;
    bool flag;
    for (int currNode = 0; currNode < length; currNode++) {
        do {
            flag = false;
            random = Random::randomInteger();
            for (int lastNode = 0; lastNode < length; lastNode++) {
                if (start[lastNode] == random && start[lastNode] != 0)
                    flag = true;
            }

        } while (flag);
        start[currNode] = random;
    }
}


void DestructionSpectrum::statisticDestroySystem(vector<double>& destroySystem, const int& M) {
    for (int pos = 0; pos < destroySystem.size(); pos++)
        destroySystem[pos] /= M;
}
