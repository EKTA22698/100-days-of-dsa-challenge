/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/
#include <stdio.h>

int main() {
    int n, i;
    int a[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 0) {
        return 0;
    }

    int k = 1;  
    for (i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            a[k] = a[i];
            k++;
        }
    }
    for (i = 0; i < k; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
