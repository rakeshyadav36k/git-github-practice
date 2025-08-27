/**
 * Given an integer array arr[]. 
 * Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. 
 * A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.
 */

#include <bits/stdc++.h>
using namespace std;
int countTriangles(int arr[], int n) {
    // Sort the array
    sort(arr, arr + n);
    int count = 0;

    // Fix the third element
    for (int k = 2; k < n; k++) {
        int i = 0, j = k - 1;
        while (i < j) {
            // Check if arr[i] + arr[j] > arr[k]
            if (arr[i] + arr[j] > arr[k]) {
                // If yes, all elements from i to j can form a triangle with k
                count += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {4, 6, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of triangles: " << countTriangles(arr, n) << endl;
    return 0;
}
