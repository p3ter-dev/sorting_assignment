#include <vector>
using namespace std;

void swap(vector<int>& arr, int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int pivot(vector<int>& arr, int start, int end) {
    int pivotValue = arr[start];
    int swapIndex = start;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < pivotValue) {
            swapIndex++;
            swap(arr, swapIndex, i);
        }
    }
    swap(arr, start, swapIndex);
    return swapIndex;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = pivot(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}