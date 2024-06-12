#include <iostream>
#ifndef UTILITY_HPP
#define UTILITY_HPP

int randomInt(int min, int max);

inline int randomInt(int min, int max) {
    return (rand() % (max - min)) + min;
}

#endif // UTILITY_HPP