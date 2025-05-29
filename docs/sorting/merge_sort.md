# Algorithm

The Merge Sort algorithm follows a `Divide-and-Conquer` approach:

1. Divide: Divide the n-element sequence to be sorted into two halves.
2. Conquer: Sort the two subsequences recursively using merge sort.
3. Combine: Merge the two sorted subsequences to produce the sorted answer.

The recursion “bottoms out” when the sequence to be sorted has length 1, in which case there is no work to be done, since every sequence of length 1 is already in sorted order.

## Steps

### Divide

We can easily split the input sequence into two halves using start and end indices as parameters

### Conquer

We keep dividing until the input subsequence has length 1, which means that it is already sorted. Then we invoke our `merge` logic (in `Combine`) that combines 2 sorted subsequences into one.

### Combine

This is the heart of the Merge Sort algorithm. The merge algorithm takes two sorted input sequences as its input and outputs a sorted combined sequence.

## Recurrence Relation

Since the divide is a constant time operation, and the conquer is an abstraction for combine, the only time taken is the one taken up by the combine operation.

Each combine operation is `O(m)`, where `m` is the length of the input given to the `merge` function, but how many total combine operations have been performed? This number is of the order of `n`.

So, the time complexity of Merge Sort is `O(n * m)` (please read till the end `m` will come out to be `lg(n)`), but how do we find `m`.

```
T(n) = {
    if n == 1
        1
    else
        2 * T(n / 2)
}
```

[Figure 2.3 from Intro to Algo book]

If we have an input of length 8. Then, there are:

1. 1 merge operation with length 4 + 4 -> time taken: 8 c
2. 2 merge operations with length 2 + 2 -> time taken: 8 c
3. 4 merge operations with length 1 + 1 -> time taken 8 c

At each level, the combined time taken by all the merge operations is `O(n)`, and there are `lg(n) + 1` such levels, since we split the input in half. Therefore, the time complexity of Merge Sort is `O(n * lg(n))`.

## Optimizations

It makes sense to 'coarsen' the leaves of the recursion in Merge Sort by using Insertion Sort within Merge Sort when subproblems become sufficiently small.
