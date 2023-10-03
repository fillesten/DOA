//
// Created by margi on 2023-09-06.
//

#include "ListGeneration.h"


std::vector<int> FallingVec(int storlek) {
    std::vector<int> fallingVec;
    for (int i = storlek; i > 0; i--) { fallingVec.push_back(i); }
    return fallingVec;
}
std::vector<int> RandomVec(int storlek) {
    std::vector<int> randomVec(storlek);
    // First create an instance of a random engine.
    std::random_device rnd;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine{ rnd() };  // Generates random integers
    std::uniform_int_distribution<int> dist{ 1, 10000 }; //the range, 1 to 10 000

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };
    generate(begin(randomVec), end(randomVec), gen);
    return randomVec;
}
std::vector<int> RisingVec(int storlek) {
    std::vector<int> risingVec;
    for (int i = 0; i < storlek; i++) { risingVec.push_back(i); }
    return risingVec;
}
std::vector<int> SameVec(int storlek) {
    std::vector<int> SameVec;
    for (size_t i = 0; i < storlek; i++) { SameVec.push_back(13); }
    return SameVec;
}

