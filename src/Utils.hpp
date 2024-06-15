#pragma once
#ifndef UTILITY_HPP
#define UTILITY_HPP
#include <iostream>
#include <random>
#include <cstdlib>


inline float randomFloat(float min,float max){
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::normal_distribution<float> distribution(min, max);
    float randomFloat = distribution(gen);
    return randomFloat;
}

inline int randomInt(int min, int max){
    return (rand() % (max - min)) + min;
}

#endif // UTILITY_HPP