# Choosing Problem

## Description
Given `N` elements, and a integer `K`, how to find the `K-th` max element?

## Algorithm

### Simple Algorithm

#### Algorithm-A
The easiest method that everyone including stupid person understand is sorting these
elements firstly. And then, we can easily find the `K-th` max element. Besides, we can
easily find the `X-th` max element as well.   
It is obvious to see that this algorithm is not effective as we just need `K-th` not
`X-th`.
If we use the most effective swapping sort algorithm, the time complexity is `O(NlogN)`,
but if using the simple sort algorithm, the time complexity is `O(N^2)`.

#### Algorithm-B
Input `K` elements, and sort it. Keep comparing the remaining elements with `K-th` element
in that sort array. If bigger, remove `K-th` element, and put new elements into.
Keep doing this, the `K-th` element is `K-th` max element. 
The time complexity is `O(N^2)`.

### Use Priority Queue Algorithm

#### Algorithm-C
Insert all `N` elements into a priority queue and then call function `deleteMin()` `N-K` times.
Then call function `findMin()`, that is the `K-th` max element.
The time complexity is `O(NlogN)`

#### Algorithm-D
Since just needing `K-th` maximum element, we just need to maintain the `K` size priority queue.
If element is bigger than root value.(`findMin()`), then `deleteMin()` and insert this element. 
