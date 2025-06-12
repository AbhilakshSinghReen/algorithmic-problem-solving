#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <functional>
#include <vector>

int binarySearchOverFunctionInRange(
        int lowerBound, int upperBound, std::function<int(int)> fx, int target);

#endif // BINARY_SEARCH_H
