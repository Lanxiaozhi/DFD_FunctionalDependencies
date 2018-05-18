/*
@author Zhi Kou
@version 1.0
@created at 2018/5/18
*/

#ifndef FD_SET_H
#define FD_SET_H
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> _union(vector<int> v1, vector<int> v2);

vector<int> _difference(vector<int> v1, vector<int> v2);

vector<int> _intersection(vector<int> v1, vector<int> v2);

#endif //FD_SET_H