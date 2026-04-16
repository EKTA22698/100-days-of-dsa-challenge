/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple hash map using arrays (since C doesn't have built-in hashmap)
int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Hash map arrays
    int hash[2 * MAX + 1];  // to store indices
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -1;

    int offset = MAX; // to handle negative sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Case 2: sum seen before
        if (hash[sum + offset] != -1) {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            // Store first occurrence
            hash[sum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));
    return 0;
}