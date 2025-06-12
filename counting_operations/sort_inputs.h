#ifndef SORT_INPUTS_H
#define SORT_INPUTS_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;
vector<int> generateRandomList(int size);
vector<int> generateAscendingList(int size);
vector<int> generateDescendingList(int size);
vector<int> generateFewItemsList();
void saveListToCSV(ofstream &file, const string &type, int size, const vector<int> &data);

#endif
