//
// Created by Timofey Dankevich on 11/12/2020.
//

#ifndef RELIABILITY_NETWORK_UTILITIESWATCH_H
#define RELIABILITY_NETWORK_UTILITIESWATCH_H

class UtilitiesWatch {
    public:
        static void watchDestroySystem(double *destroySystem, int capacity);
        static void watchOrderArray(double* orderArray, int capacity);
        static void watchVisitedNodes(double* visitedNodes, int capacity);
        static void watchRelationArray(int** relationArray, int lines, int columns);
        static void watchStatesArray(double* statesArray, int capacity);
};
#endif //RELIABILITY_NETWORK_UTILITIESWATCH_H
