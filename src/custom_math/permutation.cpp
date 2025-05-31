
#include <stdexcept>
#include <string>
#include <vector>

#include "permutation.h"

using namespace std;

// TODO: make this a template
// TODO: document this clearly
void permuteInPlace(vector<int> &inputArray, vector<int> &destinationIndices,
        bool resetDestinationIndices, bool validateDestinationIndices) {

    int n = inputArray.size();
    int nd = destinationIndices.size();

    if (validateDestinationIndices) {
        if (nd != n) {
            throw runtime_error(
                    "Cannot permute the given array length of destinationIndices is not "
                    "the same as the length of inputArray. " +
                    to_string(n) + " != " + to_string(nd) + ".");
        }

        for (int i = 0; i < n; i++) {
            if (destinationIndices[i] < 0 && destinationIndices[i] >= n) {
                throw runtime_error("Cannot permute the given array as a destination index is out "
                                    "of bounds. destinationIndex's index: " +
                                    to_string(i) + ", length of inputArray: " + to_string(n) + ".");
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (destinationIndices[i] >= n) { // already visited
            continue;
        }

        int currentIndex = i;
        int currentValue = inputArray[i];
        while (destinationIndices[currentIndex] < n) {
            int destinationIndex = destinationIndices[currentIndex];
            int destinationOriginalValue = inputArray[destinationIndex];

            inputArray[destinationIndex] = currentValue;

            destinationIndices[currentIndex] += n;

            currentValue = destinationOriginalValue;
            currentIndex = destinationIndex;
        }
    }

    if (resetDestinationIndices) {
        for (int i = 0; i < n; i++) {
            destinationIndices[i] -= n;
        }
    }
}