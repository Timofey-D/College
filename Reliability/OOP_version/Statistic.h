//
// Created by Timofey Dankevich on 17/12/2020.
//

#ifndef RELIABILITY_NETWORK_STATISTIC_H
#define RELIABILITY_NETWORK_STATISTIC_H


class Statistic {
public:
    /// The method returns an average value of integer or floating array
    static double getAverage(const double *sequence, const int &length);
    /// deviation  sqrt((1-2)^2 + (2-2)^2 + (3-2)^2) / 3 - 1
    static double getDeviation(const double *sequence, const int &length, const double &average);
    static double fact(double k);
    static double permutation(double n, double k);
    /// The method allows to sort some arrays.
    static void bubbleSort(int* start, int length);
};

#endif //RELIABILITY_NETWORK_STATISTIC_H