#include <vector>

using namespace std;

// TODO: test this
// TODO: add template
// TODO: add comparator function
void insertionSort(vector<int> &inputArray) {
    // This function implements the In Place version of the algorithm defined in
    // the docs.

    for (int i = 1; i < inputArray.size(); i++) {
        int elementToInsert = inputArray[i];

        // TODO: we can just have one loop for the check and the moving forward,
        // based on inverse comparator, as the given algorithm performs worse in the
        // best case as well

        // Find the index at which to insert
        int insertionIndex = i;
        for (int j = 0; j < i; j++) {
            if (inputArray[j] > elementToInsert) {
                insertionIndex = j;
                break;
            }
        }

        // Move remaining sorted elements forward by 1
        for (int j = i; j > insertionIndex; j--) {
            inputArray[j] = inputArray[j - 1];
        }

        inputArray[insertionIndex] = elementToInsert;
    }
}
