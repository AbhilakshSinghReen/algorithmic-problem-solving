#include <vector>

using namespace std;

void merge(vector<int> &inputArray, int p, int q, int r, vector<int> &extraSpace,
        int sentinel = INT_MAX) {
    // index q is included in the first array
    int sortedArr1Start = 0;       // start the first sorted array at index 0
    int sortedArr1End = q - p + 2; // first sorted array has (q - p + 1) elements, and one sentinel
    int sortedArr2Start =
            sortedArr1End + 1; // start the second sorted array after the first sorted array
    int sortedArr2End = sortedArr2Start +
                        (r - q + 1); // second sorted array has (r - p) elements, and one sentinel

    // Set the sorted arrays into the extra space
    for (int i = sortedArr1Start; i < sortedArr1End; i++) {
        extraSpace[i] = inputArray[p + i - sortedArr1Start];
    }
    extraSpace[sortedArr1End] = sentinel;

    for (int i = sortedArr2Start; i < sortedArr2End; i++) {
        extraSpace[i] = inputArray[q + 1 + i - sortedArr2Start];
    }
    extraSpace[sortedArr2End] = sentinel;

    // Merge the 2 sorted arrays present in extra space
    int sortedArr1Current = sortedArr1Start, sortedArr2Current = sortedArr2Start;
    for (int i = p; i <= r; i++) {
        if (extraSpace[sortedArr1Current] < extraSpace[sortedArr2Current]) {
            inputArray[i] = extraSpace[sortedArr1Current];
            sortedArr1Current++;
        } else {
            inputArray[i] = extraSpace[sortedArr2Current];
            sortedArr2Current++;
        }
    }
}

void mergeSortRecursive(
        vector<int> &inputArray, int subArrayStart, int subArrayEnd, vector<int> &extraSpace) {
    if (subArrayEnd <= subArrayStart) {
        return;
    }

    int subArrayMid = (subArrayStart + subArrayEnd) / 2;
    mergeSortRecursive(inputArray, subArrayStart, subArrayMid, extraSpace);
    mergeSortRecursive(inputArray, subArrayMid + 1, subArrayEnd, extraSpace);
    merge(inputArray, subArrayStart, subArrayMid, subArrayEnd, extraSpace);
}

// TODO: test this
// TODO: add template (for the helper methods as well)
// TODO: add comparator function (for the helper methods as well)
void mergeSort(vector<int> &inputArray) {
    vector<int> extraSpace(inputArray.size() + 2);

    mergeSortRecursive(inputArray, 0, inputArray.size() - 1, extraSpace);
}
