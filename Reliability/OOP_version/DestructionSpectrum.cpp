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
    vector<int> permutationEdges;
    Utilities::nullifyVector(destroySystem);
    for (int m = 1; m <= M; m++) {
        permutationEdges.assign(graph.getE(), 0);
        createPermutationEdges(permutationEdges);
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
    vector<int> permutationEdges(graph.getE(), 0);
    createPermutationEdges(permutationEdges);
    graph.removeAllConnection();
    main::createConnection(graph);
    for (int index = 0; index < graph.getE(); index++) {
        Utilities::showVector(permutationEdges, false);
        turnOff[permutationEdges[index] - 1]++;
        graph.removeConnection(permutationEdges[index]);
        permutationEdges[index] = 0;
        graph.clearVisit();
        graph.findPath(T1);
        if (!graph.checkNode(T2) || !graph.checkNode(T3)) {
            return index;
        }
    }
    return -1;
}


void DestructionSpectrum::createPermutationEdges(vector<int>& permutation) {
    int random;
    bool flag;
    for (int currNode = 0; currNode < permutation.size(); currNode++) {
        do {
            flag = false;
            random = Random::randomInteger();
            for (int lastNode = 0; lastNode < permutation.size(); lastNode++) {
                if (permutation[lastNode] == random && permutation[lastNode] != 0)
                    flag = true;
            }

        } while (flag);
        permutation[currNode] = random;
    }
}


void DestructionSpectrum::statisticDestroySystem(vector<double>& destroySystem, const int& M) {
    for (int pos = 0; pos < destroySystem.size(); pos++)
        destroySystem[pos] /= M;
}
