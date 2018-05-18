/*
@author Zhi Kou
@version 1.0
@created at 2018/5/17
*/

#include "Node.h"

vector<Attrs> Node::getAttr() {
	return _attr;
}

bool Node::visited() {
	return _visited;
}

void Node::visit() {
	_visited = true;
}

bool Node::isCategoryNull() {
	return _category._null;
}

bool Node::isDependency() {
	return _category._dependency;
}

bool Node::isNonDependency() {
	return _category._nonDependency;
}

bool Node::isMinimal() {
	return _category._minimal;
}

bool Node::isMaximal() {
	return _category._maximal;
}

bool Node::isCandidate() {
	return _category._candidate;
}

bool Node::isCandidateMinimalDep() {
	return _category._candidate && _category._minimal && _category._dependency;
}

bool Node::isCandidataMaximalNonDep() {
	return _category._candidate && _category._maximal && _category._nonDependency;
}

void Node::updataDependencyType(bool dependency, bool nonDependency,
	bool minimal, bool maximal, bool candicate) {
	_category._dependency = dependency;
	_category._nonDependency = nonDependency;
	_category._minimal = minimal;
	_category._dependency = dependency;
	_category._dependency = dependency;
	_category._null = false;
}