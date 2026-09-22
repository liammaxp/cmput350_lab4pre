#include <cstddef>  // size_t

#include "timer.h"
#include <cstdint>
#include <iostream>
#include <list>
#include <random>
#include <vector>

constexpr size_t SIZE = 16000000;

int main() {
    std::mt19937_64 rng(0);
    std::list<uint64_t> values;
    Timer timer;
    for (size_t i = 0; i < SIZE; ++i){
        values.push_back(rng());
    }

    auto listInsertTime = timer.click<Timer::Micros>();
    std::cout << listInsertTime << '\n';
    rng.seed(0);
    std::vector<uint64_t> vectorValues;

    Timer timer2;
    for (size_t i = 0; i < SIZE; ++i){
        vectorValues.push_back(rng());
    }
    auto vectorTime = timer2.click<Timer::Micros>();
    rng.seed(0);
    std::vector<uint64_t> reservedVector;
    reservedVector.reserve(SIZE);

    Timer timer3;
    for (size_t i = 0; i < SIZE; ++i){
        reservedVector.push_back(rng());
    }
    auto reservedVectorTime = timer3.click<Timer::Micros>();

    Timer sumTimer;
    uint64_t sum = 0;
    for (uint64_t value : values){
        sum += value;
    }
    auto sumTime = sumTimer.click<Timer::Micros>();
    std::cout << sum << '\n';
    std::cout << sumTime << '\n';

    sum = 0;

    Timer vectorSumTimer;
    for (uint64_t value : reservedVector){
        sum += value;
    }
    auto vectorSumTime = vectorSumTimer.click<Timer::Micros>();
    std::cout << sum << '\n';
    std::cout << vectorSumTime << '\n';
    std::cout << listInsertTime << '\n';
    std::cout << vectorTime << '\n';
    std::cout << reservedVectorTime << '\n';
    // test here...
    return 0;
}
