/*
@author Zhi Kou
@version 1.0
@created at 2018/5/17
*/

#ifndef NODE_H
#define NODE_H
#include <vector>
#include <bitset>
#include "constants.h"
using namespace std;

class Node {
private:
	vector<Attrs> _attr;
	struct{
		bool _null = true;
		bool _dependency = false;
		bool _nonDependency = false;
		bool _minimal = false;
		bool _maximal = false;
		bool _candidate = false;
	} _category;
	bool _visited = false;

public:
	Node(){}
	Node(vector<Attrs> v) : _attr(v){}
	Node(Attrs a) {
		_attr.push_back(a);
	}
	~Node(){}
	vector<Attrs> getAttr();
	bool visited();
	void visit();
	bool isCategoryNull();
	bool isDependency();
	bool isNonDependency();
	bool isMinimal();
	bool isMaximal();
	bool isCandidate();
	bool isCandidateMinimalDep();
	bool isCandidataMaximalNonDep();
	void updataDependencyType(bool dependency = false, bool nonDependency = false , 
		bool minimal = false, bool maximal = false, bool candicate = false);

	explicit operator bool() {
		return !_attr.empty();
	}
};

#endif // !NODE_H

