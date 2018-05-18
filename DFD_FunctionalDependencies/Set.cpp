/*
@author Zhi Kou
@version 1.0
@created at 2018/5/18
*/

#include "Set.h"

vector<int> _union(vector<int> v1, vector<int> v2) {
	set<int> s1(v1.begin(), v1.end());
	set<int> s2(v2.begin(), v2.end());
	vector<int> result;
	auto iter = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), result.begin());
	result.resize(iter - result.begin());
	return result;
}

vector<int> _difference(vector<int> v1, vector<int> v2) {
	set<int> s1(v1.begin(), v1.end());
	set<int> s2(v2.begin(), v2.end());
	vector<int> result;
	auto iter = set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), result.begin());
	result.resize(iter - result.begin());
	return result;
}

vector<int> _intersection(vector<int> v1, vector<int> v2) {
	set<int> s1(v1.begin(), v1.end());
	set<int> s2(v2.begin(), v2.end());
	vector<int> result;
	auto iter = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), result.begin());
	result.resize(iter - result.begin());
	return result;
}