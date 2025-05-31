#include <algorithm>
#include <random>
#include <unordered_map>
#include <vector>

#include "permutation.h"

using namespace std;

inline int randIntInRange(int min, int max) {
    static random_device randomDevice;    // Hardware entropy source (non-deterministic)
    static mt19937 mtRNG(randomDevice()); // Mersenne Twister PRNG

    int randNum = mtRNG();
    int rangeSize = max - min + 1;
    int randNumInRange = min + (randNum % rangeSize);
    return randNumInRange;
}

void randomizeBySortingInPlace(vector<int> &inputArray) {
    int n = inputArray.size();

    vector<pair<int, int>> rankArray(n);
    int rankUpperBound = pow(n, 3) - 1;
    for (int i = 0; i < n; i++) {
        int rank = randIntInRange(0, rankUpperBound);
        rankArray[i] = make_pair(i, rank);
    }

    sort(rankArray.begin(), rankArray.end(),
            [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; });

    vector<int> shuffledIndices(n);
    for (int i = 0; i < n; i++) {
        shuffledIndices[i] = rankArray[i].first;
    }

    permuteInPlace(inputArray, shuffledIndices);
}

void randomizeInPlace(vector<int> &inputArray) {
    int n = inputArray.size();

    for (int i = 0; i < n; i++) {
        // generate a random number from in [i, n)
        int destinationIndex = randIntInRange(i, n - 1);
        swap(inputArray[i], inputArray[destinationIndex]);
    }
}