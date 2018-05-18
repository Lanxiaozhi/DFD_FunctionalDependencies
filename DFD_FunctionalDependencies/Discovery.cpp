/*
@author Zhi Kou
@version 1.0
@created at 2018/5/17
*/

#include "Discovery.h"
#include "Set.h"
#include <iostream>

Node pickSeed(vector<Attrs> seeds) {
	return seeds[0];
}

vector<Node> findLHSs(Attrs RHS, vector<vector<unsigned>> data) {
	Attrs seed = ~(R ^ RHS);
	vector<Attrs> seeds;//R/{RHS}
	//TODO
	while (!seeds.empty()) {
		Node node = pickSeed(seeds);
		while (node) {
			if (node.visited()) {
				if (node.isCandidate()) {
					if (node.isDependency()) {
						if (node.isMinimal()) {
							minDeps.push_back(node);
						}
					}
					else {
						if (node.isMaximal()) {
							maxNonDeps.push_back(node);
						}
					}
					node.updataDependencyType();
				}
			}
			else {
				//node.inferCategory();
				//TODO
				if (node.isCategoryNull()) {
					//computePartitions(node, RHS);
					//TODO
				}
			}
			node = pickNextNode(node);
		}
		seeds = generateNextSeeds();
	}
	return minDeps;
}

Node pickNextNode(Node node) {
	Node nextNode;
	if (node.isCandidateMinimalDep()) {
		vector<Node> S = map.getUncheckedSubsets(node);
		vector<Node> T = map.getPrunedSets(node);
		//S = _difference(S, T);
		if (S.empty()) {
			minDeps.push_back(node);
		}
		else {
			nextNode = S[0];
			trace.push(node);
			return nextNode;
		}
	}
	else if (node.isCandidataMaximalNonDep()) {
		vector<Node> S = map.getUncheckedSupersets(node);
		vector<Node> P = map.getPrunedSupersets(node);
		//S = _difference(S, P);
		if (S.empty()) {
			maxNonDeps.push_back(node);
		}
		else {
			nextNode = S[0];
			trace.push(node);
			return nextNode;
		}
	}
	else {
		nextNode = trace.top();
		//trace.pop();
		return nextNode;
	}
}

vector<Attrs> getComplement(vector<Attrs> vec) {
	
	vector<Attrs> newVec;
	for (auto attr : vec) {
		newVec.push_back(~attr);
	}
	return newVec;
}

vector<Attrs> minimize(vector<Attrs> vec) {
	//TODO
}

vector<Attrs> generateNextSeeds() {
	vector<Attrs> seeds = {};
	vector<Attrs> newSeeds = {};
	for (auto maxNonDep : maxNonDeps) {
		vector<Attrs> cMaxNonDep = getComplement(maxNonDep.getAttr());
		if (seeds.empty()) {
			int seedsLength = maxNonDep.getAttr().size();
			for (auto setBitIndex : cMaxNonDep) {
				cout << setBitIndex << " ";
				//TODO
			}
		}
		else {
			for (auto dep : seeds) {
				for (auto setBitIndex : cMaxNonDep) {
					cout << setBitIndex << " ";
					//TODO
					newSeeds.push_back(dep & setBitIndex);
				}
			}
			vector<Attrs> minimizedNewDeps = minimize(newSeeds);
			seeds = {};
			for (auto newSeed : minimizedNewDeps) {
				seeds.push_back(newSeed);
			}
			newSeeds = {};
		}
	}
	//seeds = _difference(seeds,	minDeps);
	return seeds;
}