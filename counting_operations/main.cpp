#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "insertionSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "sort_inputs.h"

using namespace std;

vector<int> generateRandomList(int size);
vector<int> generateAscendingList(int size);
vector<int> generateDescendingList(int size);
vector<int> generateFewItemsList();

template <typename Func>
long long measureSort(Func sortFunc, vector<int>& data) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(data);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void quickSortWrapper(vector<int>& arr, long long& comparisonCount) {
    quickSort(arr, 0, arr.size() - 1, comparisonCount);
}

void mergeSortWrapper(vector<int>& arr, long long& comparisonCount) {
    mergeSort(arr, 0, arr.size() - 1, comparisonCount);
}

int main() {
    vector<int> sizes = {1000, 3000, 5000};

    ofstream csv("results_with_comparisons.csv");
    csv << "Size,Type,InsertionSort_Time(ms),InsertionSort_Comparisons,"
           "QuickSort_Time(ms),QuickSort_Comparisons,"
           "MergeSort_Time(ms),MergeSort_Comparisons\n";

    for (int size : sizes) {
        vector<pair<string, vector<int>>> scenarios = {
            {"Random", generateRandomList(size)},
            {"Ascending", generateAscendingList(size)},
            {"Descending", generateDescendingList(size)}
        };

        for (auto [type, original] : scenarios) {
            long long comparisons1 = 0, comparisons2 = 0, comparisons3 = 0;

            vector<int> list1 = original;
            long long time1 = measureSort([&](vector<int>& data) {
                insertionSort(data, comparisons1);
            }, list1);

            vector<int> list2 = original;
            long long time2 = measureSort([&](vector<int>& data) {
                quickSortWrapper(data, comparisons2);
            }, list2);

            vector<int> list3 = original;
            long long time3 = measureSort([&](vector<int>& data) {
                mergeSortWrapper(data, comparisons3);
            }, list3);

            cout << "Size: " << size << " | Type: " << type << endl;
            cout << "Insertion Sort: " << time1 << " ms, Comparisons: " << comparisons1 << endl;
            cout << "Quick Sort: " << time2 << " ms, Comparisons: " << comparisons2 << endl;
            cout << "Merge Sort: " << time3 << " ms, Comparisons: " << comparisons3 << endl;
            cout << "-------------------------" << endl;

            csv << size << "," << type << ","
                << time1 << "," << comparisons1 << ","
                << time2 << "," << comparisons2 << ","
                << time3 << "," << comparisons3 << "\n";
        }
    }

    // Few items test
    vector<int> few = generateFewItemsList();
    long long c1 = 0, c2 = 0, c3 = 0;

    cout << "Few Items Test (20 items)" << endl;
    cout << "Insertion Sort: "
         << measureSort([&](vector<int>& data) { insertionSort(data, c1); }, few)
         << " ms, Comparisons: " << c1 << endl;

    cout << "Quick Sort: "
         << measureSort([&](vector<int>& data) { quickSortWrapper(data, c2); }, few)
         << " ms, Comparisons: " << c2 << endl;

    cout << "Merge Sort: "
         << measureSort([&](vector<int>& data) { mergeSortWrapper(data, c3); }, few)
         << " ms, Comparisons: " << c3 << endl;

    csv.close();
    return 0;
}
