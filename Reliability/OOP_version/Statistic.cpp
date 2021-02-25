//
// Created by Timofey Dankevich on 17/12/2020.
//

#include "Statistic.h"
#include <cmath>

/// The method returns an average value of integer or floating array
double Statistic::getAverage(const double* sequence, const int& length) {
    double average = 0;
    for (int value = 0; value < length; value++)
        average += sequence[value];
    return average / length;
}

/// deviation  sqrt((1-2)^2 + (2-2)^2 + (3-2)^2) / 3 - 1
double Statistic::getDeviation(const double* sequence, const int& length, const double& average) {
    double deviation = 0;
    for (int value = 0; value < length; ++value)
        deviation += pow(sequence[value] - average, 2);
    deviation /= (double) (length - 1);
    return sqrt(deviation);
}

double Statistic::fact(double k) {
    if (k <= 1)
        return 1;
    else
        return fact(k - 1) * k;
}

double Statistic::permutation(double n, double k) {
    return fact(n) / (fact(k) * fact(n - k));
}

/// The method allows to sort some arrays.
void Statistic::bubbleSort(int* start, int length) {
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