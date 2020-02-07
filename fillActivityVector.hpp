//  ActivityTracker
//  fillActivityVector.hpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.

#ifndef fillWalkVector_hpp
#define fillWalkVector_hpp

#include <stdexcept>
#include <iostream>
#include <vector>
#include <ctime>

#include "completeActivity.hpp"

void fillActivityVector(std::vector<completeActivity>& fillAllActivites);
double doubleFromString(const std::string& str);

#endif /* fillWalkVector_hpp */
