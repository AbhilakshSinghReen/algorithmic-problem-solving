#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <vector>

void permuteInPlace(std::vector<int> &inputArray, std::vector<int> &destinationIndices,
        bool resetDestinationIndices = true, bool validateDestinationIndices = true);

#endif // PERMUTATION_H
