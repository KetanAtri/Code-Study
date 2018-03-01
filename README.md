# Code-Study
This repository contains all the programs I write for DSA studying purposes

## Sorting Algorithms
1. Bubble Sort - Compare adjacent elements, if the former is greater than the latter, swap the two; this operation is repeated n-1 times to sort the entire array
2. Selection Sort - Select the least element, swap it with the first element. Repeat this process with n-1 times, each time looking for the least element in the remaining array.
3. Insertion Sort - Start from second element, keep swapping it back till a smaller element is reached. The process is repeated for the remaining elements as well to sort the entire array
4. Merge Sort - Divide and conquer strategy is used, divide the array till single element is reached. Merge these divisions while keeping ordering under consideration. Sort from C++ can be used as it performs equally well.
5. Heap Sort - Use the heap structure (priority queue in C++) to store the elements then remove and insert them one by one to get the sorted list.
6. Quick Sort - Choose a pivot element, order the element around it. Repeat the procedure on either sides of the pivot element to sort the entire array
7. Counting sort - Keep the count of different elements, display the elements in sorted order based on counts
8. Radix sort - Sorting is done based on digit, starting with the LSD or Least significant digit. Individual sorting is done using counting sort, repeated till all the digits are exhausted.

## Problems to be solved
1. The Next Palindrome - http://www.spoj.com/problems/PALIN/<br>
Some test cases: 71416, 121, 1111, 1234, 567864<br>
Expected output: 71417, 131, 1221, 1331, 568865

### Message
Please don't make any changes to the master branch, create your own branch and make the changes. I will pull the branches occasionally (if needed). The command for doing so using git CLT (command line tool) is:<br>
`git checkout -b branch-name`, here `checkout` is for switching branches and `-b` is for creating a new branch.
