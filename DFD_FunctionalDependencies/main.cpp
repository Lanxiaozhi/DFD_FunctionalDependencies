/*
@author Zhi Kou
@version 1.0
@created at 2018/5/17
*/

#include <bitset>
#include "Preprocessor.h"
#include "Discovery.h"
#include "constants.h"
using namespace std;

bool isUnique(int attr) {

}

int main() {
	unsigned long rowNum = 100000; // estimated number of row
	unsigned long colNum = 15; // [exact] number of column
	string filePath = "data.txt";
	vector<vector<unsigned>> data;
	data.reserve(rowNum);
	Preprocessor prep(filePath, colNum);

	//    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	prep.getData(data);
	//    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
	//    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / 1e9 <<std::endl;

	    //// ===== DEBUG ======
	    //for(auto row: data) {
	    //    for(auto elem: row) {
	    //        cout << elem << " ";
	    //    }
	    //    cout << endl;
	    //}
	    //// ==== DEBUGEND ====

	//for (auto column : data) {
	//	if (isUnique(Attribute)) {
	//		R <- R/{A}
	//		add(A->R) to F;
	//	}
	//}

	unordered_map<Attrs, int>Result;
	for (int RHS = 1; RHS <= 15; RHS++) {
		vector<Node> LHSs = findLHSs(RHS, data);
		for (auto node: LHSs) {
			for (auto attr : node.getAttr()) {
				Result.insert(pair<Attrs, int>(attr, RHS));
			}
		}
	}


	return 0;
}