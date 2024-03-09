/**
 * @file 01_ArrayInversionCount.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
在合併排序的過程中，當兩個子陣列合併時，我們可以記錄反轉對的數量。
具體來說，當從左半部分的子陣列中選取元素時，如果在右半部分的子陣列中有比它小的元素，
則表示產生了一個反轉對。在進行合併時，我們可以在計算反轉對的同時進行合併操作。
在這個修改後的 merge 函式中，我們在每次選取右半部分的元素時，都會計算反轉對的數量。
當 A[i] 大於 A[j] 時，A[i] 及其右邊的所有元素都會與 A[j] 構成反轉對，
因此我們可以通過 (mid - i + 1) 的方式計算出反轉對的數量。
*/

#include <vector>
using namespace std;

// Merge function to count inversions
long long merge(vector<int>& A, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }

    while (j <= right) {
        temp[k++] = A[j++];
    }

    for (int idx = left, k = 0; idx <= right; ++idx, ++k) {
        A[idx] = temp[k];
    }

    return inversions;
}

// Merge sort function to count inversions
long long mergeSort(vector<int>& A, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += mergeSort(A, left, mid);
        inversions += mergeSort(A, mid + 1, right);
        inversions += merge(A, left, mid, right);
    }
    if (inversions < 1000000000) {
        return inversions;
    }else {
        return -1;
    }
}

int solution(vector<int>& A) {
    return static_cast<int>(mergeSort(A, 0, A.size() - 1));
}
