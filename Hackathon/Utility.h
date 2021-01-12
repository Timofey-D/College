//
// Created by Timofey Dankevich on 29/12/2020.
//

#ifndef RELIABILITY_HAKATON_UTILITY_H
#define RELIABILITY_HAKATON_UTILITY_H
#include <vector>

class Utility {
public:
    static void getCleanVector(std::vector<double>& vec, int value);
    static void getCleanVector(std::vector<int>& vec, int value);
    static void showVector(const std::vector<int>& vec);
    static void showVector(const std::vector<double>& vec);
};


#endif //RELIABILITY_HAKATON_UTILITY_H
