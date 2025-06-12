#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high, long long& comparisonCount) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisonCount++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, long long& comparisonCount) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisonCount);
        quickSort(arr, low, pi - 1, comparisonCount);
        quickSort(arr, pi + 1, high, comparisonCount);
    }
}
