//
// Created by Timofey Dankevich on 11/12/2020.
//

#include <iostream>
#include <Reliability.h>
#include <array>
#include <UtilitiesWatch.h>
using namespace std;

/// That's block of the methods, which allows to print out contain of some arrays.
/// The method prints out the DestroySystem array.
void UtilitiesWatch::watchDestroySystem(double_t* destroySystem, int capacity) {
    for (int index = 0; index < capacity; index++)
        cout << destroySystem[index] << " ";
    cout << endl;
}

/// The method prints out the OrderArray array.
void UtilitiesWatch::watchOrderArray(double* orderArray, int capacity) {
    for (int index = 0; index < capacity; index++)
        cout << orderArray[index] << " ";
    cout << endl;
}

/// The method prints out the visitedNodes array.
void UtilitiesWatch::watchVisitedNodes(double* visitedNodes, int capacity) {
    for (int index = 0; index < capacity; index++)
        cout << visitedNodes[index] << " ";
    cout << endl;
}

/// The method prints out the relation array.
void UtilitiesWatch::watchRelationArray(int** relationArray, int lines, int columns) {
    for (size_t i = 0; i < lines; i++) {
        for (size_t j = 0; j < columns; j++)
            cout << relationArray[i][j] << " ";
        cout << endl;
    }
}

/// The method prints out the statesEdges array.
void UtilitiesWatch::watchStatesArray(double* statesArray, int capacity) {
    for (int index = 0; index < capacity; index++)
        cout << statesArray[index] << " ";
    cout << endl;
}
