# Insertion-Sort-and-Quicksort

Objective - Implement Insertion Sort and Quicksort, then compare their performance on a variety of inputs.

In this assignment, I was required to open a binary file consisting of the data to be operated on. There are three files: a sorted file (sorted.bin), a random file (random.bin), and a reverse file (reverse.bin). After opening a file, my program would then sort it first using insertion sort, then quicksort. Each time a duplicate array was created so that the original file remained unchanged. After each sort finished I recorded how long it took for the sort to complete and printed it to the console.

Challenges - There were a few problems with my original Quicksort algorithm which took a bit of time to debug. The biggest problem was that my quicksort was attempting to access an index that was outside of the original array. This was mainly the result of inconsistencies in my main regarding how long the array was, and whether I should be using length or length - 1. After a thorough debug I was able to correct all these inconsistencies and my program ran perfectly.
