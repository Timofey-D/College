/**
 * Author: Timofey Dankevich
 * Date: 29.11.2020
 * The beginning of the development: 01.11.2020
 The program is designed to estimate the reliability of the network, which is presented like a graph.
 Program was developed by Dmitry Shaulov, Timofey Dankevich. The code was realised by Dankevich Timofey.
 */

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <UtilitiesWatch.h>
#include "Random.h"
using namespace std;

/// The array displays the connections in the graph and number of each edge.
static int full_Relation[20][20] = {
//       1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20
/*1*/   {0,  1,  0,  0,  5,  0,  0,  26, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*2*/   {1,  0,  2,  0,  0,  0,  0,  0,  0,  27, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*3*/   {0,  2,  0,  3,  0,  0,  0,  0,  0,  0,  0,  28, 0,  0,  0,  0,  0,  0,  0,  0},
/*4*/   {0,  0,  3,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  29, 0,  0,  0,  0,  0,  0},
/*5*/   {5,  0,  0,  4,  0,  30, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*6*/   {0,  0,  0,  0,  30, 0,  6,  0,  0,  0,  0,  0,  0,  0,  15, 0,  0,  0,  0,  0},
/*7*/   {0,  0,  0,  0,  0,  6,  0,  7,  0,  0,  0,  0,  0,  0,  0,  0,  22, 0,  0,  0},
/*8*/   {26, 0,  0,  0,  0,  0,  7,  0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*9*/   {0,  0,  0,  0,  0,  0,  0,  8,  0,  9,  0,  0,  0,  0,  0,  0,  0,  23, 0,  0},
/*10*/  {0,  27, 0,  0,  0,  0,  0,  0,  9,  0,  10, 0,  0,  0,  0,  0,  0,  0,  0,  0},
/*11*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  10, 0,  11, 0,  0,  0,  0,  0,  0,  24, 0},
/*12*/  {0,  0,  28, 0,  0,  0,  0,  0,  0,  0,  11, 0,  12, 0,  0,  0,  0,  0,  0,  0},
/*13*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  12, 0,  13, 0,  0,  0,  0,  0,  25},
/*14*/  {0,  0,  0,  29, 0,  0,  0,  0,  0,  0,  0,  0,  13, 0,  14, 0,  0,  0,  0,  0},
/*15*/  {0,  0,  0,  0,  0,  15, 0,  0,  0,  0,  0,  0,  0,  14, 0,  21, 0,  0,  0,  0},
/*16*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  21, 0,  16, 0,  0,  20},
/*17*/  {0,  0,  0,  0,  0,  0,  22, 0,  0,  0,  0,  0,  0,  0,  0,  16, 0,  17, 0,  0},
/*18*/  {0,  0,  0,  0,  0,  0,  0,  0,  23, 0,  0,  0,  0,  0,  0,  0,  17, 0,  18, 0},
/*19*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  24, 0,  0,  0,  0,  0,  0,  18, 0,  19},
/*20*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  25, 0,  0,  20, 0,  0,  19, 0}
};

/// The array is created to back up the full_Relation array after each round.
static int primary_Relation[20][20] = {
//       1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20
/*1*/   {0,  1,  0,  0,  5,  0,  0,  26, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*2*/   {1,  0,  2,  0,  0,  0,  0,  0,  0,  27, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*3*/   {0,  2,  0,  3,  0,  0,  0,  0,  0,  0,  0,  28, 0,  0,  0,  0,  0,  0,  0,  0},
/*4*/   {0,  0,  3,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  29, 0,  0,  0,  0,  0,  0},
/*5*/   {5,  0,  0,  4,  0,  30, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*6*/   {0,  0,  0,  0,  30, 0,  6,  0,  0,  0,  0,  0,  0,  0,  15, 0,  0,  0,  0,  0},
/*7*/   {0,  0,  0,  0,  0,  6,  0,  7,  0,  0,  0,  0,  0,  0,  0,  0,  22, 0,  0,  0},
/*8*/   {26, 0,  0,  0,  0,  0,  7,  0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*9*/   {0,  0,  0,  0,  0,  0,  0,  8,  0,  9,  0,  0,  0,  0,  0,  0,  0,  23, 0,  0},
/*10*/  {0,  27, 0,  0,  0,  0,  0,  0,  9,  0,  10, 0,  0,  0,  0,  0,  0,  0,  0,  0},
/*11*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  10, 0,  11, 0,  0,  0,  0,  0,  0,  24, 0},
/*12*/  {0,  0,  28, 0,  0,  0,  0,  0,  0,  0,  11, 0,  12, 0,  0,  0,  0,  0,  0,  0},
/*13*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  12, 0,  13, 0,  0,  0,  0,  0,  25},
/*14*/  {0,  0,  0,  29, 0,  0,  0,  0,  0,  0,  0,  0,  13, 0,  14, 0,  0,  0,  0,  0},
/*15*/  {0,  0,  0,  0,  0,  15, 0,  0,  0,  0,  0,  0,  0,  14, 0,  21, 0,  0,  0,  0},
/*16*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  21, 0,  16, 0,  0,  20},
/*17*/  {0,  0,  0,  0,  0,  0,  22, 0,  0,  0,  0,  0,  0,  0,  0,  16, 0,  17, 0,  0},
/*18*/  {0,  0,  0,  0,  0,  0,  0,  0,  23, 0,  0,  0,  0,  0,  0,  0,  17, 0,  18, 0},
/*19*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  24, 0,  0,  0,  0,  0,  0,  18, 0,  19},
/*20*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  25, 0,  0,  20, 0,  0,  19, 0}
};

/// The lengths of relation array
static const int length_Full_Relation = sizeof(full_Relation) / sizeof(*full_Relation);
/// The number of vertices in a graph
static const int number_Of_Vertices = 20;
/// The Number of edges in a graph
static const int number_Of_Edges = 30;

/// The array displays what nodes were visitedNodes by goRoundAGraph method.
array<int, number_Of_Vertices> visitedNodes{};

/// The array contains a state of the edges.
array<double, number_Of_Edges> statesEdges{};

/// The array contains a different permutation of edges.
array<int, number_Of_Edges> orderArray{};

/// The array will store value of number of fall down of system.
array<double, number_Of_Edges> destroySystem{};


/// The method allows to sort some arrays.
__unused void bubbleSort(int* start, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (start[j] >= start[j + 1]) {
                int change = start[j];
                start[j] = start[j + 1];
                start[j + 1] = change;
            }
        }
    }
}

/// That's block of the methods, which allows to recover a content of some array.
/// The method recovers the destroySystem array.
__unused void recoverDestroySystemArray() {
    destroySystem.fill(0);
}

/// The method clears the visitedNodes array.
void recoverVisitedNodes() {
    visitedNodes.fill(0);
}

/// The method recovers the array relations after each round changing state.
void recoverRelationArray() {
    for (int node = 0; node < length_Full_Relation; node++) {
        for (int edge = 0; edge < length_Full_Relation; edge++)
            full_Relation[node][edge] = primary_Relation[node][edge];
    }
}

/// The method recovers the order array.
void recoverOrderArray() {
    orderArray.fill(0);
}

/// The method checks there is node in the
bool checkVisitedNodes(const int& node) {
    for (int i : visitedNodes) {
        if (i == node)
            return true;
    }
    return false;
}

/// The method adds a node in the visitedNodes array
void addNodeToVisitedNodes(const int& node) {
    for (int & visitedNode : visitedNodes) {
        if (visitedNode == 0) {
            visitedNode = node;
            break;
        }
    }
}

/// Method goes round the graph. Method is recursive.
void goRoundAGraph(const int& start) {
    addNodeToVisitedNodes(start);
    for (int i = 0; i < length_Full_Relation; i++) {
        if ( full_Relation[start - 1][i] != 0 && checkVisitedNodes(i + 1) == 0)
            goRoundAGraph(i + 1);
    }
}

/// The method changes a state of edge and shapes the array relations.
void changeValueOfStateOfEdges(const double& probability) {
    int visitedEdges[number_Of_Edges];
    for (auto & connected : full_Relation) {
        for (int & edge : connected) {
            if (edge != 0) {
                visitedEdges[edge - 1] = 1;
                edge = statesEdges[edge - 1] <= probability ? edge : 0;
            }
        }
    }
}

/// The method fills the statesEdges array random values.
void fillStatesArray() {
    for (double & state : statesEdges)
        state = Random::randomNumber();
}

/// The method prints out a state of the graph.
void infoGraph() {
    for (int round = 1; round <= number_Of_Vertices; round++) {
        for (int i = 0; i < length_Full_Relation; i++) {
            for (int j = 0; j < length_Full_Relation; j++) {
                if ( full_Relation[i][j] != 0 && (round == (i + 1)) )
                    printf("%-3d>>%3d%2s", round, j + 1, "");
            }
        }
        cout << endl;
    }
}

/// The method sets randomly a state of the edges.
int monteCarloMethod(const int& M, const double& P, const int& T1, const int& T2, const int& T3) {
    int R = 0;
    for (int round = 1; round <= M; round++) {
        fillStatesArray();
        changeValueOfStateOfEdges(P);
        goRoundAGraph(T1);
        if (checkVisitedNodes(T2) == 1 && checkVisitedNodes(T3) == 1 )
            R++;
        recoverVisitedNodes();
        recoverRelationArray();
    }
    return R;
}

/**
 * The method prints out results obtained using Monte Carlo method.
 * */
void showMonteCarlo(const int& T1, const int& T2, const int& T3) {
    double possibilities[] = {
            0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.95, 0.99, 1.0
    };
    int M[] = {
            1000, 10000, 50000
    };
    for (int m : M) {
        cout << "____________________________________________" << endl;
        printf("%s = %d\n", "M", m);
        cout << "____________________________________________" << endl;
        printf("%12s|%13s|%12s\n", "Probability", "Reliability", "R/M");
        for (double possibility : possibilities) {
            double R = monteCarloMethod(m, possibility, T1, T2, T3);
            printf("%12.2f| %11.f | %11.4f\n", possibility, R, (R / m));
        }
    }
}

double getAverage(const double* sequence, const int& length) {
    double average = 0;
    for (int value = 0; value < length; value++)
        average += sequence[value];
    return average / length;
}

/// deviation  sqrt((1-2)^2 + (2-2)^2 + (3-2)^2) / 3 - 1
double getDeviation(const double* sequence, const int& length, const double& average) {
    double deviation = 0;
    for (int value = 0; value < length; ++value)
        deviation += pow(sequence[value] - average, 2);
    deviation /= (double) (length - 1);
    return sqrt(deviation);
}

void showMonteCarlo10Times(const int& T1, const int& T2, const int& T3) {
    cout << "____________________________" << endl;
    double probability = 0.95;
    int M = 1000;
    array<double, 10> average {};
    average.fill(0);
    printf("%2s = %-5d%s%2s = %.2f\n", "M", M, "|", "P", probability);
    for (int i = 1; i <= 10; i++) {
        double R = monteCarloMethod(M, probability, T1, T2, T3);
        average[i - 1] = R / M;
        printf("%2d >> %s = %-5.0f%s%4s = %.3f\n", i, "R", R, "|", "R/M", R/M);
    }
    cout << "____________________________" << endl;
    double AVR = getAverage(average.begin(), average.size());
    double deviation = getDeviation(average.begin(), average.size(), AVR);
    printf("Average R:\nAR = %.2f\n"
           "Ratio Average R and M:\n"
           "AR/M = %.4f\nR.E = %.10f\n", AVR, AVR / M, deviation / AVR);
}

void permutationArray() {
    int random;
    bool flag;
    for (int currNode = 0; currNode < number_Of_Edges; currNode++) {
        do {
            flag = false;
            random = Random::randomInteger();
            for (int lastNode = 0; lastNode < number_Of_Edges; lastNode++) {
                if (orderArray[lastNode] == random && orderArray[lastNode] != 0)
                    flag = true;
            }

        } while (flag == 1);
        orderArray[currNode] = random;
    }
}

bool findEdgePermArray(const int& numberOfEdge) {
    for (int & edge : orderArray) {
        if (edge == numberOfEdge)
            return true;
    }
    return false;
}

void turnOffEdges() {
    for (int i = 0; i < length_Full_Relation; i++) {
        for (int j = 0; j < length_Full_Relation; j++) {
            if (full_Relation[i][j] != 0 && !findEdgePermArray(full_Relation[i][j]))
                    full_Relation[i][j] = 0;
        }
    }
}

void computePercentageDestroySystem(const double& M) {
    for (double & index : destroySystem)
        index /= M;
}

void roundsDestroySystem(const double& M, const int& T1, const int& T2, const int& T3) {
    for (int m = 1; m <= M; m++) {
        recoverOrderArray();
        permutationArray();
        recoverRelationArray();
        for (int index = 0; index < number_Of_Edges; index++) {
            orderArray[index] = 0;
            turnOffEdges();
            recoverVisitedNodes();
            goRoundAGraph(T1);
            if ( checkVisitedNodes(T2) == 0 || checkVisitedNodes(T3) == 0 ) {
                destroySystem[index]++;
                recoverVisitedNodes();
                break;
            }
        }
    }
}

double getDestructionSpectrum(const double* F) {
    double result = 0;
    for (int index = 0; index < number_Of_Edges; index++)
        result += destroySystem[index] * F[index];
    return result;
}

double fact(double k) {
    if (k <= 1)
        return 1;
    else
        return fact(k - 1) * k;
}

double permutation(double n, double k) {
    return fact(n) / (fact(k) * fact(n - k));
}

array<double, number_Of_Edges> createFVector(const double& q, const double& p) {
    array<double, number_Of_Edges> F {};
    F.fill(0);
    for (int edge = 0; edge < F.size(); edge++) {
        for (int loop = edge + 1; loop <= number_Of_Edges; loop++) {
            F[edge] += permutation(number_Of_Edges, loop) * pow(q, loop) * pow(p, number_Of_Edges - loop);
        }
    }
    return F;
}

void showDestructionSpectrum(const int& T1, const int& T2, const int& T3) {
    array<double, number_Of_Edges> F {};
    array<double, 11> Q {};
    Q.fill(0);
    array<double, 11> P = {
            0.1, 0.2, 0.3, 0.4, 0.5,
            0.6, 0.7, 0.8, 0.9, 0.95,
            0.99
    };
    double M[] = {
            1000, 10000, 50000
    };
    for (double m : M) {
        roundsDestroySystem(m, T1, T2, T3);
        computePercentageDestroySystem(m);
        cout << "_________________________________________" << endl;
        printf("%s = %0.f\n", "Destruction Spectrum", m);
        for (int i = 0; i < P.size(); i++)
            printf("%-15.2f%s", P[i], "|");
        cout << endl;
        for (int p = P.size() - 1; p >= 0; p--) {
            F = createFVector(1 - P[p], P[p]);
            double destructionSpectrum = getDestructionSpectrum(F.begin());
            printf("%-15.10f%s", destructionSpectrum, "|");
        }
        printf("\n%s%2s%10s%s\n", "№", "|", "Number of destroy", "|");
        for (int edge = 0; edge < number_Of_Edges; ++edge)
            printf("%2d%s%17f%s\n", (edge + 1), "|", destroySystem[edge], "|");
    }
}

void showDestructionSpectrum10Times(const int& T1, const int& T2, const int& T3) {
    double P = 0.95;
    double Q = 1 - P;
    int M = 1000;
    array<double, number_Of_Edges> F {};
    array<double, 10> average {};
    cout << "_________________________________________" << endl;
    printf("%s = %d\n%s = %.2f\n", "Destruction Spectrum", M, "P", P);
    F = createFVector(Q, P);
    for (int round = 0; round < 1; ++round) {
        roundsDestroySystem(M, T1, T2, T3);
        computePercentageDestroySystem(M);
        double destructionSpectrum = getDestructionSpectrum(F.begin());
        printf("%s =%2d%-5s%-15.15f%s\n", "№", round + 1, "|",  destructionSpectrum, "|");
        average[round] = destructionSpectrum;
        recoverDestroySystemArray();
    }
    double AVE = getAverage(average.begin(), average.size());
    double deviation = getDeviation(average.begin(), average.size(), AVE);
    printf("%s = %.8f\n%s = %.8f", "Average", AVE, "R.E", deviation / AVE);
}

/// The method main is an entrance program.
int main() {
    srand(time(0));
    int T1 = 2;
    int T2 = 7;
    int T3 = 18;
    printf("TERMINALS: T1 = %d T2 = %d T3 = %d\n", T1, T2, T3);
    infoGraph();
    showMonteCarlo(T1, T2, T3);
    showDestructionSpectrum(T1, T2, T3);
    showMonteCarlo10Times(T1, T2, T3);
    showDestructionSpectrum10Times(T1, T2, T3);
    return 0;
}