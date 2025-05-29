# Algorithm

The Merge Sort algorithm follows a `Divide-and-Conquer` approach:

1. Divide: Divide the n-element sequence to be sorted into two halves.
2. Conquer: Sort the two subsequences recursively using merge sort.
3. Combine: Merge the two sorted subsequences to produce the sorted answer.

The recursion “bottoms out” when the sequence to be sorted has length 1, in which case there is no work to be done, since every sequence of length 1 is already in sorted order.

## Divide

We can easily split the input sequence into two halves using start and end indices as parameters

## Conquer

We keep dividing until the input subsequence has length 1, which means that it is already sorted. Then we invoke our `merge` logic (in `Combine`) that combines 2 sorted subsequences into one.

## Combine

This is the heart of the Merge Sort algorithm. The merge algorithm takes two sorted input sequences as its input and outputs a sorted combined sequence.
