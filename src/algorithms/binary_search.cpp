#include <climits>
#include <functional>
#include <iostream>
#include <vector>

#include "binary_search.h"

using namespace std;

int binarySearchOverFunctionInRange(
        int lowerBound, int upperBound, function<int(int)> fx, int target) {
    int low = lowerBound;
    int high = upperBound;
    int result = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (fx(mid) >= target) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}
