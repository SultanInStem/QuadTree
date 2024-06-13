#include <iostream>
#include <cstdlib>
#ifndef UTILITY_HPP
#define UTILITY_HPP

int randomInt(int min, int max);

inline int randomInt(int min, int max) {
    return (rand() % (max - min)) + min;
}
float randomFloat(float min, float max) {
    float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return min + random * (max - min);
}
#endif // UTILITY_HPP