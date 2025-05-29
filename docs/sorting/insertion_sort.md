# Example

[Referred From: Intro to Algos, third edition]
Insertion sort works the way many people sort a hand of playing cards. We start with an empty left hand and the cards face down on the table. We then remove one card at a time from the table and insert it into the correct position in the left hand. To find the correct position for a card, we compare it with each of the cards already in the hand, from right to left. At all times, the cards held in the left hand are sorted, and these cards were originally the top cards of the pile on the table.

# Algorithm

Not In Place:

1. Given an input array `nums`, create another array `output` of the same size to store the sorted values.
2. Place the first element of `nums` as it is into `output`.
3. Iterate `i` from `1` to `nums.size()`:
4. Take the element `i` from `nums` and start comparing it with the elements in `output`, stop at the first element that is greater than it. Let this be index `x` in `output`.
5. Move all elements from index `x` till the end, one index forward in `output`.
6. Place element `i` from `nums` in index `x` in `output`.
7. Move to the next input element, i.e. `i++`.
8. Repeat steps `4 - 6` as long as `i < nums.size()`

The above algorithm allocates `O(n)` extra space (for the output). But, we can get rid of this by sorting in place.

In Place:
Instead of constructing a separate output array, the in place version of this algorithm uses a part of the input array to store the output.

1. Start at element `1` of the input array (`nums`), i.e. iterate `i` from `1` to `nums.size()`.
2. Take element `i` from `nums` and compare it with all the elements before it, let's say the first element bigger than it is at index `x`.
3. Insert the element `i` at index `x` in the input array, following the approach defined in the `Not In Place` version of this algorithm.

You will note that at any moment, all elements in the array before index `i` are sorted, as `i` reaches the end, the entire array is sorted.

Insertion Sort can also be expressed as a recursive procedure, but that is unnecessary.
TODO: elaborate this further and add the code for this

The scanning part of the Insertion Sort algorithm is searching in a sorted array, this can be made more efficient by using Binary Search. However, as the shifting part still takes linear time, using Binary Search for scanning will not change the overall time complexity of the algorithm.
TODO: add code for this approach

# Complexity Analysis

## Time

The first loops iterates through the entire array (`i ∈ [0, n)`) and the second loops iterates from the start of the array to the element in the first loop (`j ∈ [0, x]`) and then iterates from the insertion position till the end of the array to move elements forward to make space for insertion (`j ∈ [x, i)`).

Time Complexity: O(n ^ 2)

## Space

Space Complexity (In Place): O(1)
