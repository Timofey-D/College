//
// Created by Timofey Dankevich on 17/12/2020.
//

#include "Utilities.h"
#include <iostream>
#include <iomanip>

void Utilities::nullifyArray(double* start, int length) {
    for (int pos = 0; pos < length; pos++)
        start[pos] = 0;
}

void Utilities::nullifyVector(vector<double>& vector) {
    vector.assign(vector.size(), 0);
}

void Utilities::showArray(double* array, int length) {
    for (int pos = 0; pos < length; pos++)
        cout << array[pos] << " ";
    cout << endl;
}

void Utilities::showVector(vector<double>& vector, bool endline) {
    char symbol = endline ? '\n' : ' ';
    int orderNumber = 1;
    for (int pos = 0; pos < vector.size(); pos++) {
        if (endline)
            printf("%02d%2s%10.5f%5s%c", (orderNumber + pos), "|", vector[pos], "|", symbol);
        else
            cout << vector[pos] << symbol;
    }
    cout << endl;
}


void Utilities::showVector(vector<int>& vector, bool endline) {
    char symbol = endline ? '\n' : ' ';
    int orderNumber = 1;
    for (int pos = 0; pos < vector.size(); pos++) {
        if (endline)
            printf("%02d%2s%10.5d%5s%c", (orderNumber + pos), "|", vector[pos], "|", symbol);
        else
            cout << vector[pos] << symbol;
    }
    cout << endl;
}
