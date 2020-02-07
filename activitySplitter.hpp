//  ActivityTracker
//  activitySplitter.hpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.
// 'Data structure kung fu'

#ifndef activitySplitter_hpp

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

#include "completeActivity.hpp"

class activitySplitter {
private:
	// keys ordered by string, set is ordered. nested data strutures: sets within a map
	std::map<std::string, std::set<completeActivity>> activity_map;

public:
	// each incoming object gets mapped to an 'act', creates a new set for each
	// completeActivity object by inserting each into a map
	void doSplit(std::vector<completeActivity> & activities) {
		for (completeActivity act : activities) {
			activity_map[act.getWalkName()].insert(act);
		}
	}

	void dump() {

	}

};












#endif /* activitySplitter_hpp */
