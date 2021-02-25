//
// Created by Timofey Dankevich on 29/12/2020.
//

#include "Random.h"

#include "Random.h"
#include <random>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

/// That's block of the methods, which allows to generate a random value.
/// The method randomize a number between 0 and 1.
double Random::randomNumber() {
    std::mt19937_64 rng;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);
    // ready to generate random numbers
    double currentRandomNumber = unif(rng);
    return currentRandomNumber;
}

/// The method randomize a integer number between 1 and 30.
int Random::randomInteger(int start, int end) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> intDist(start, end); // define the range
    return intDist(gen);
}