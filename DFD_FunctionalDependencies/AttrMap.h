#ifndef FD_ATTR_MAP_H
#define FD_ATTR_MAP_H

#include <unordered_map>
#include "constants.h"
#include "Node.h"

class AttrMap {
private:
	unordered_map<Attrs, Attrs> _map;

public:
	vector<Attrs> getUncheckedSubsets(Node node);
};

#endif // !FD_ATTR_MAP_H
