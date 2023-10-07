//
// Created by margi on 2023-10-04.
//


#include "Generation.h"


//generates primes up untill given N
std::vector<int> GeneratePrimes(int N) {
    std::vector<int> primeVec;
    primeVec.push_back(2);
    int numberToCheck = 3;

    while (primeVec.size() < N) {
        bool isPrime = true;
        for (int prime : primeVec) {
            if (numberToCheck % prime == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primeVec.push_back(numberToCheck);
        }
        numberToCheck += 2;
    }
    return primeVec;
}

