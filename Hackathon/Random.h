//
// Created by Timofey Dankevich on 29/12/2020.
//

#ifndef RELIABILITY_HAKATON_RANDOM_H
#define RELIABILITY_HAKATON_RANDOM_H


class Random {
public:
    static double randomNumber();

/// The method randomize a integer number between 1 and 30.
    static int randomInteger(int start, int end);
};


#endif //RELIABILITY_HAKATON_RANDOM_H
