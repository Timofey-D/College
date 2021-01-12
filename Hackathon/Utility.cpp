//
// Created by Timofey Dankevich on 29/12/2020.
//

#include <iostream>
#include "Utility.h"
#include <vector>

void Utility::getCleanVector(std::vector<double>& vec, int value) {
    vec.assign(vec.size(), value);
}

void Utility::getCleanVector(std::vector<int>& vec, int value) {
    vec.assign(vec.size(), value);
}

void Utility::showVector(const std::vector<int>& vec) {
    for (auto & item : vec)
        std::cout << item << " ";
    std::cout << std::endl;
}

void Utility::showVector(const std::vector<double>& vec) {
    for (auto & item : vec)
        std::cout << item << " ";
    std::cout << std::endl;
}