//
// Created by Timofey Dankevich on 17/12/2020.
//

#ifndef RELIABILITY_NETWORK_UTILITIES_H
#define RELIABILITY_NETWORK_UTILITIES_H
#include <vector>
using namespace std;

class Utilities {
public:
    static void nullifyArray(double* start, int length);
    static void nullifyVector(vector<double>& vector);
    static void showArray(double* array, int length);
    static void showVector(vector<double>& vector, bool endline);
    static void showVector(vector<int>& vector, bool endline);
};


#endif //RELIABILITY_NETWORK_UTILITIES_H

