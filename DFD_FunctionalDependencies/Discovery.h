/*
	@author Zhi Kou
	@version 1.0
	@created at 2018/5/17
*/

#ifndef FD_DFD_H
#define FD_DFD_H

#include <vector>
#include <bitset>
#include <set>
#include <stack>
#include "constants.h"
#include "Node.h"
using namespace std;

vector<Node> minDeps, maxNonDeps;

stack<Node> trace;

vector<Node> findLHSs(Attrs RHS, vector<vector<unsigned>> data);

Node pickNextNode();

vector<Attrs> getComplement(vector<Attrs> vec);

vector<Attrs> minimize(vector<Attrs> vec);

vector<Attrs> generateNextSeeds();

#endif //FD_DFD_H
