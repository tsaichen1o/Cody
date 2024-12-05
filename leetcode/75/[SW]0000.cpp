/**
 * @file [SW]0000.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief countTriplets
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int countTriplets(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3, int D) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();

    int count = 0;
    int i = 0, j = 0, k = 0;

    // Sort the arrays to maintain order.
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end());

    // Sliding windows
    while (i < n1 && j < n2 && k < n3) {
        // Check the conditions between arr1[i], arr2[j], arr3[k]
        if (abs(arr1[i] - arr2[j]) <= D && abs(arr2[j] - arr3[k]) <= D && abs(arr1[i] - arr3[k]) <= D) {
            // Calculate how many elements in each array fit within the condition.
            int startI = i, startJ = j, startK = k;

            while (i < n1 && abs(arr1[startI] - arr1[i]) <= D) {
                i++;
            }
            while (j < n2 && abs(arr2[startJ] - arr2[j]) <= D) {
                j++;
            }
            while (k < n3 && abs(arr3[startK] - arr3[k]) <= D) {
                k++;
            }
            // 最大值 - 最小值 <= D

            count += (i - startI) * (j - startJ) * (k - startK);
        } else {
            // Move the window to keep values under D.
            if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
                i++;
            } else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
                j++;
            } else {
                k++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr1 = {1, 5, 5};
    vector<int> arr2 = {3, 4, 5};
    vector<int> arr3 = {6, 6, 8};
    int D = 1;

    int result = countTriplets(arr1, arr2, arr3, D);
    cout << "Number of valid triplets: " << result << endl;

    return 0;
}

// Time Complexity: O(n1 + n2 + n3), where n1, n2, and n3 are the lengths of the three arrays.
// Space Complexity: O(1), as we are using a constant amount of extra space.

#include <iostream>
#include <vector>
using namespace std;

int countTuples(const vector<int>& A, const vector<int>& B, const vector<int>& C, int D) {
    int n = A.size();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int j = 0, k = 0;
        while (j < n && k < n) {
            while (j < n && abs(A[i] - B[j]) > D) j++;
            while (k < n && abs(A[i] - C[k]) > D) k++;
            
            if (j < n && k < n && abs(B[j] - C[k]) <= D) {
                // Find the next j such that abs(A[i] - B[j]) <= D && abs(B[j] - C[k]) <= D
                int j_end = j;
                while (j_end < n && abs(A[i] - B[j_end]) <= D && abs(B[j_end] - C[k]) <= D) j_end++;
                count += (j_end - j);
                k++;
            } else if (j < n && k < n) {
                k++;
            }
        }
    }
    
    return count;
}

int main() {
    vector<int> arr1 = {1, 5, 5};
    vector<int> arr2 = {3, 4, 5};
    vector<int> arr3 = {6, 6, 8};
    int D = 1;
    
    cout << countTuples(arr1, arr2, arr3, D) << endl;
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)

---

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countTriplets(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3, int D) {
    int count = 0;
    int n = arr1.size();

    // Iterate over all possible combinations of elements from arr1, arr2, arr3
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                // Check if the conditions are met for the given D
                if (abs(arr1[i] - arr2[j]) <= D &&
                    abs(arr2[j] - arr3[k]) <= D &&
                    abs(arr1[i] - arr3[k]) <= D) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr1 = {1, 5, 5};
    vector<int> arr2 = {3, 4, 5};
    vector<int> arr3 = {6, 6, 8};
    int D = 1;

    int result = countTriplets(arr1, arr2, arr3, D);
    cout << "Number of triplets: " << result << endl;

    return 0;
}

// Time Complexity: O(n^3), where n is the size of the input arrays.
// Space Complexity: O(1), as we are using a constant amount of extra space.