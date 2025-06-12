#include <cassert>
#include <iostream>

#include "algorithms/binary_search.h"
#include "data_structures/trie.h"
#include "metrics/timer.h"

using namespace std;

int main() {
    auto fx = [](int x) {
        //
        return x * x * x;
    };

    for (int i = 1; i < 17; i++) {
        int square = i * i * i;

        int x = binarySearchOverFunctionInRange(0, square, fx, square);
    }

    return 0;
}
