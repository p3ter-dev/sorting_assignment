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

void quickSortWrapper(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

void mergeSortWrapper(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> sizes = {1000, 3000, 5000};

    ofstream csvFile("sort_results.csv");
    csvFile << "Size,Type,Algorithm,Time(ms)" << endl;

    for (int size : sizes) {
        vector<pair<string, vector<int>>> scenarios = {
            {"Random", generateRandomList(size)},
            {"Ascending", generateAscendingList(size)},
            {"Descending", generateDescendingList(size)}
        };

        for (auto [type, original] : scenarios) {
            vector<int> list1 = original;
            long long time1 = measureSort(insertionSort, list1);
            csvFile << size << "," << type << ",Insertion Sort," << time1 << endl;

            vector<int> list2 = original;
            long long time2 = measureSort(quickSortWrapper, list2);
            csvFile << size << "," << type << ",Quick Sort," << time2 << endl;

            vector<int> list3 = original;
            long long time3 = measureSort(mergeSortWrapper, list3);
            csvFile << size << "," << type << ",Merge Sort," << time3 << endl;

            // Optional: also print to console
            cout << "Size: " << size << " | Type: " << type << endl;
            cout << "Insertion Sort: " << time1 << " ms" << endl;
            cout << "Quick Sort: " << time2 << " ms" << endl;
            cout << "Merge Sort: " << time3 << " ms" << endl;
            cout << "-------------------------" << endl;
        }
    }

    vector<int> few = generateFewItemsList();
    long long t1 = measureSort(insertionSort, few);
    long long t2 = measureSort(quickSortWrapper, few);
    long long t3 = measureSort(mergeSortWrapper, few);

    csvFile << "20,Few Items,Insertion Sort," << t1 << endl;
    csvFile << "20,Few Items,Quick Sort," << t2 << endl;
    csvFile << "20,Few Items,Merge Sort," << t3 << endl;

    cout << "Few Items Test (20 items)" << endl;
    cout << "Insertion Sort: " << t1 << " ms" << endl;
    cout << "Quick Sort: " << t2 << " ms" << endl;
    cout << "Merge Sort: " << t3 << " ms" << endl;

    csvFile.close();

    return 0;
}