#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, long long& comparisonCount) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int currentValue = arr[i];
        int j = i - 1;
        while (j >= 0 && ++comparisonCount && arr[j] > currentValue) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currentValue;
    }
}
