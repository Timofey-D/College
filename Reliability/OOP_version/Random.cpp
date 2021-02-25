//
// Created by Timofey Dankevich on 11/12/2020.
//

#include "Random.h"
#include <random>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

/// That's block of the methods, which allows to generate a random value.
/// The method randomize a number between 0 and 1.
double Random::randomNumber() {
    constexpr int FLOAT_MIN = 0;
    constexpr int FLOAT_MAX = 1;
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<float> floating(FLOAT_MIN, FLOAT_MAX);
    return floating(rd);
}

/// The method randomize a integer number between 1 and 30.
int Random::randomInteger() {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> intDist(1, 30); // define the range
    return intDist(gen);
}

/// The method randomize a integer number between 1 and 30.
int Random::randomIntegerRange(int start, int end) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> intDist(start, end); // define the range
    return intDist(gen);
}