#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

vector<int> generateRandomList(int size) {
    vector<int> v(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);

    for (int& val : v) val = dis(gen);
    return v;
}

vector<int> generateAscendingList(int size) {
    vector<int> v(size);
    for (int i = 0; i < size; ++i) v[i] = i + 1;
    return v;
}

vector<int> generateDescendingList(int size) {
    vector<int> v(size);
    for (int i = 0; i < size; ++i) v[i] = size - i;
    return v;
}

vector<int> generateFewItemsList() {
    return generateRandomList(30);
}

void saveListToCSV(ofstream &file, const string &type, int size, const vector<int> &data) {
    file << type << "," << size << ",";
    for (int i = 0; i < data.size(); ++i) {
        file << data[i];
        if (i != data.size() - 1) file << " ";
    }
    file << "\n";
}