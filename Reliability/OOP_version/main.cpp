/**
 * Author: Timofey Dankevich
 * Date: 29.11.2020
 * The beginning of the development: 01.11.2020
 The program is designed to estimate the reliability of the network, which is presented like a graph.
 Program was developed by Dmitry Shaulov, Timofey Dankevich. The code was realised by Dankevich Timofey.
 */
#include <algorithm>
#include <iostream>
#include <array>
#include "main.h"
#include "Statistic.h"
#include <MonteCarloMethod.h>
#include <DestructionSpectrum.h>
#include <Utilities.h>
#include <Graph.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


void showDestructionSpectrum_FirstTask(Graph& graph, const int& T1, const int& T2, const int& T3) {
    vector<double> F;
    F.resize(graph.getE());
    Utilities::nullifyVector(F);
    vector<double> statisticDestroy;
    statisticDestroy.resize(graph.getE());
    Utilities::nullifyVector(statisticDestroy);
    array<double, 11> P = {
        0.1, 0.2, 0.3, 0.4, 0.5,
        0.6, 0.7, 0.8, 0.9, 0.95,0.99
    };
    int M[] = {
            1000/*, 10000, 50000*/
    };
    for (auto & m : M) {
        printf("%s%3s%10s%s%3s = %d\n", "#", "|", "Destroy", "|", "M", m);
        statisticDestroy = DestructionSpectrum::getDestroySystem(graph, m, T1, T2, T3);
        DestructionSpectrum::statisticDestroySystem(statisticDestroy, m);
        Utilities::showVector(statisticDestroy, true);
        for (int pos = 0; pos < P.size(); pos++) {
            F = DestructionSpectrum::createFVector(P[pos], graph.getE());
            printf("%2.2f = %.10f\n", P[P.size() - 1 - pos], DestructionSpectrum::getPF(F, statisticDestroy));
        }
        cout << endl;
    }
}


void showDestructionSpectrum_SecondTask(Graph& graph, int M, int round, double P, int& T1, int& T2, int& T3) {
    vector<double> PF;
    PF.resize(round);
    Utilities::nullifyVector(PF);
    vector<double> F;
    F.resize(graph.getE());
    Utilities::nullifyVector(F);
    F = DestructionSpectrum::createFVector(P, graph.getE());
    vector<double> statisticDestroy;
    statisticDestroy.resize(graph.getE());
    Utilities::nullifyVector(statisticDestroy);
    printf("%2s%1s%3s = %d\n", "#", "|", "M", M);
    for (int loop = 0; loop < round; loop++) {
        statisticDestroy = DestructionSpectrum::getDestroySystem(graph, M, T1, T2, T3);
        PF[loop] = DestructionSpectrum::getPF(F, statisticDestroy);
        printf("%2d%-3s%.10f\n", loop + 1, "|", DestructionSpectrum::getPF(F, statisticDestroy));
    }
    double APF = Statistic::getAverage(&PF[0], PF.size());
    double deviation = Statistic::getDeviation(&PF[0], PF.size(), APF);
    printf("%s = %.5f\n%s = %.10f\n%s = %.10f",
           "Average R/M", APF,
           "Deviation", deviation,
           "R.E", (deviation / APF) );
}


void showMonteCarlo_FirstTask(Graph& graph, int& T1, int& T2, int& T3) {
    int R;
    array<int, 3> M = {
            1000, 10000, 50000
    };
    array<double, 11> P = {
            0.1, 0.2, 0.3, 0.4, 0.5, 0.6,
            0.7, 0.8, 0.9, 0.95, 0.99
    };
    for (auto & m : M) {
        printf("%s = %d\n", "M", m);
        printf("%s%7s%s%7s%s%7s\n", "P", "|", "R", "|", "R/M", "|");
        for (double & p : P) {
            R = MonteCarloMethod::computeReliabilityDependsOnP(graph, m, p, T1, T2, T3);
            printf("%.2f%4s%5d%3s%.5f%3s\n", p, "|", R, "|", (double) R / m, "|");
        }
        printf("\n");
    }
}


void showMonteCarlo_SecondTask(Graph& graph, int M, double P, int round, int& T1, int& T2, int& T3) {
    int R;
    array<double, 10> RM {};
    Utilities::nullifyArray(RM.begin(), RM.size());
    printf("%s = %d\n", "M", M);
    printf("%s%7s%s%7s%s%7s\n", "P", "|", "R", "|", "R/M", "|");
    for (int loop = 0; loop < round; loop++) {
        R = MonteCarloMethod::computeReliabilityDependsOnP(graph, M, P, T1, T2, T3);
        RM[loop] = (double) R / M;
        printf("%.2f%4s%5d%3s%.5f%3s\n", P, "|", R, "|", (double) R / M, "|");
    }
    double ARM = Statistic::getAverage(RM.begin(), RM.size());
    double deviation = Statistic::getDeviation(RM.begin(), RM.size(), ARM);
    printf("%s = %.5f\n%s = %.10f\n%s = %.10f",
           "Average R/M", ARM,
           "Deviation", deviation,
           "R.E", (deviation / ARM) );
}


void showCumulativeSpectrum(Graph& graph, int T1, int T2, int T3) {
    vector<double> destroySystem(graph.getE(), 0);
    int M[] = {1000, 10000};
    for (auto & m : M) {
        printf("%s = %d\n", "M", m);
        destroySystem = DestructionSpectrum::getDestroySystem(graph, m, T1, T2, T3);
        DestructionSpectrum::cumulativeVector(destroySystem);
        DestructionSpectrum::statisticDestroySystem(destroySystem, m);
        Utilities::showVector(destroySystem, true);
    }
}


void showBimTable(const vector<vector<double>>& bimTable) {
    printf("%2s%1s", "#", "");
    for (int z = 0; z < 30; z++) {
        printf("%10d", z + 1);
    }
    cout << endl;
    for (int line = 0; line < bimTable.size(); line++) {
        printf("%2d:", line + 1);
        for (double col : bimTable[line]) {
            printf("%10.5f", col);
        }
        cout << endl;
    }
    cout << endl;
}

void getBIMTable(vector<vector<double>>& bimTable, const vector<int>& turnOffEdges, const int& destroySystem) {
    int Ai = destroySystem - 1;
    for (int pos = 0; pos < bimTable[Ai].size(); pos++) {
        bimTable[Ai][pos] += turnOffEdges[pos];
    }
}


void cumulativeBimTable(vector<vector<double>>& bimTable) {
    for (int col = 0; col < bimTable.size(); col++) {
        for (int line = 0; line < bimTable.size(); line++) {
            if ((line - 1) >= 0)
                bimTable[line][col] = bimTable[line - 1][col] + bimTable[line][col];
        }
    }
}


void division(vector<vector<double>>& bimTable, int& M) {
    for (auto & conn : bimTable) {
        for (auto & item : conn) {
            item /= (double) M;
        }
    }
}


bool contains(const vector<int>& vector, int edge) {
    for (auto & e : vector) {
        if (e == edge)
            return false;
    }
    return true;
}


void findEssentialEdge(const vector<vector<double>>& bimTable) {
    vector<int> essentialEdges;
    vector<double> maximum(30, 0);
    int max = INT16_MIN;
    int min = INT16_MAX;
    double average = 0;
    int count = 0;
    for (int line = 0; line < bimTable.size(); line++) {
        for (int col = 0; col < bimTable[line].size(); line++) {
            if (bimTable[line][col] != 0) {
                count++;
                average += bimTable[line][col];
            }
        }
    }
    average /= count;
    int important = 0;
    int unimportant = 0;
    for (int col = 0; col < bimTable.size(); col++) {
        int edge = col + 1;
        for (int line = 0; line < bimTable[col].size(); line++) {
//            if (bimTable[line][col] > average) {
//                max = bimTable[line][col];
//                maximum[edge] =
//            }
        }
    }
    cout << "Average: " << average << endl;
    Utilities::showVector(essentialEdges, false);
}


void showCumulativeBIMSpectrum(Graph& graph, int T1, int T2, int T3) {
    int destroySystem;
    vector<double> cumulativeVector(graph.getE(), 0);
    vector<int> turnOffEdges(graph.getE(), 0);
    vector<vector<double>> bimTable(graph.getE());
    vector<int> placeDestroy;
    for (auto & arr : bimTable)
        arr.resize(graph.getE(), 0);
    int M = 5;
    for (int iteration = 0; iteration < M; iteration++) {
        destroySystem = DestructionSpectrum::getCumulativeSpectrum(graph, turnOffEdges, T1, T2, T3);
        cout << destroySystem << endl;
        Utilities::showVector(turnOffEdges, false);
        cumulativeVector[destroySystem - 1]++;
        getBIMTable(bimTable, turnOffEdges, destroySystem);
        turnOffEdges.assign(graph.getE(), 0);
    }
    showBimTable(bimTable);
    cumulativeBimTable(bimTable);
    division(bimTable, M);
    findEssentialEdge(bimTable);
    showBimTable(bimTable);
}

void printStat(const vector<double>& reliabilities, double& p) {
    double max = INT16_MIN;
    int edge_max = 0;
    double min = INT16_MAX;
    int edge_min = 0;
    for (int i = 0; i < reliabilities.size(); ++i) {
        for (int j = 0; j < reliabilities.size(); ++j) {
            if (j != i) {
                if (reliabilities[i] > reliabilities[j] && reliabilities[i] > max) {
                    max = reliabilities[i];
                    edge_max = i + 1;
                    min = reliabilities[j];
                    edge_min = j + 1;
                }
                else if (reliabilities[i] < reliabilities[j] && reliabilities[i] <= min) {
                    if (reliabilities[j] > max) {
                        max = reliabilities[j];
                        edge_max = j + 1;
                    }
                    min = reliabilities[i];
                    edge_min = i + 1;
                }
            }
        }
    }
    cout << p << ":\n" << "Edge = " << edge_max << " = " << max << "\n" << "Edge = " << edge_min << " = " << min << endl;
    cout << endl;
}


void checkEdgeByMonteCarlo(Graph& graph, int& T1, int& T2, int& T3) {
    int M = 10000;
    cout << M << endl;
    double P[] = {0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    vector<double> reliabilities;
    for (auto & p : P) {
        for (int edge = 1; edge <= 30; edge++) {
            double R_down = MonteCarloMethod::computeReliability(graph, edge, 1, p, M, T1, T2, T3);
            double R_up = MonteCarloMethod::computeReliability(graph, edge, 0, p, M, T1, T2, T3);
            reliabilities.push_back((R_up - R_down) / M);
        }
        Utilities::showVector(reliabilities, false);
        printStat(reliabilities, p);
        reliabilities.clear();
    }
}

/// The method main is an entrance program.
int main() {
    auto start = chrono::high_resolution_clock::now();
    int T1 = 3;
    int T2 = 6;
    int T3 = 19;
    printf("TERMINALS:\nT1 = %d\nT2 = %d\nT3 = %d\n", T1, T2, T3);
    cout << "__________________________" << endl;
    Graph graph = Graph(20,30);
    main::createConnection(graph);
    /// The first challenge is monteCarlo for rounds: 1000, 10000, 50000
//    showMonteCarlo_FirstTask(graph, T1, T2, T3);
//    cout << endl;
    /// The second challenge is monteCarlo for round 1000 and 10 and possibility 0.95
//    showMonteCarlo_SecondTask(graph, 1000, 0.95, 10, T1, T2, T3);
//    cout << endl;
    /// The first challenge is DestructionSpectrum for rounds: 1000, 10000, 50000
//    showDestructionSpectrum_FirstTask(graph, T1, T2, T3);
//    cout << endl;
    /// The second challenge is DestructionSpectrum for round 1000 and 10 times and 0.95
//    showDestructionSpectrum_SecondTask(graph, 1000, 10, 0.95, T1, T2, T3);
//    showCumulativeSpectrum(graph, T1, T2, T2);
//    showCumulativeBIMSpectrum(graph, T1, T2, T3);
    checkEdgeByMonteCarlo(graph, T1, T2, T3);
//    int M = 10;
//    double p = 0.5;
//    MonteCarloMethod::computeReliabilityDependsOnP(graph, M, p, T1, T2, T3);
//    cout << endl;
//    MonteCarloMethod::computeReliabilityExperiment(graph, M, p, T1, T2, T3);
    auto stop = chrono::high_resolution_clock::now();
    cout << "Execution time in seconds: " << (chrono::duration_cast<seconds>(stop - start)).count() << endl;
    cout << "Execution time in nanoseconds: " << (chrono::duration_cast<nanoseconds>(stop - start)).count() << endl;
    return 0;
}

void main::createConnection(Graph& graph) {
    /// Node 1
    graph.addConnection(1, 2, 1);
    /// Node 2
    graph.addConnection(2, 3, 2);
    /// Node 3
    graph.addConnection(3, 4, 3);
    /// Node 4
    graph.addConnection(4, 5, 4);
    /// Node 5
    graph.addConnection(5, 1, 5);
    /// Node 6
    graph.addConnection(6, 7, 6);
    graph.addConnection(6, 5, 30);
    /// Node 7
    graph.addConnection(7, 8, 7);
    /// Node 8
    graph.addConnection(8, 9, 8);
    graph.addConnection(8, 1, 26);
    /// Node 9
    graph.addConnection(9, 10, 9);
    /// Node 10
    graph.addConnection(10, 11, 10);
    graph.addConnection(10, 2, 27);
    /// Node 11
    graph.addConnection(11, 12, 11);
    /// Node 12
    graph.addConnection(12, 3, 28);
    graph.addConnection(12, 13, 12);
    /// Node 13
    graph.addConnection(13, 14, 13);
    /// Node 14
    graph.addConnection(14, 15, 14);
    graph.addConnection(14, 4, 29);
    /// Node 15
    graph.addConnection(15, 6, 15);
    /// Node 16
    graph.addConnection(16, 15, 21);
    graph.addConnection(16, 17, 16);
    /// Node 17
    graph.addConnection(17, 18, 17);
    graph.addConnection(17, 7, 22);
    /// Node 18
    graph.addConnection(18, 19, 18);
    graph.addConnection(18, 9, 23);
    /// Node 19
    graph.addConnection(19, 20, 19);
    graph.addConnection(19, 11, 24);
    /// Node 20
    graph.addConnection(20, 16, 20);
    graph.addConnection(20, 13, 25);
}