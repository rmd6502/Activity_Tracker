//  ActivityTracker
//  printActivityVector.cpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

#include "printActivityVector.hpp"
#include "completeActivity.hpp"

void printActivityVector(const std::vector<completeActivity>& printThisVec) {

    for (int i = 0; i < printThisVec.size(); ++i) {

        std::cout << "Name: " << printThisVec[i].getWalkName() << '\n';

        std::cout << "Date: " << (printThisVec[i].time_member().tm_mon) + 1
            << "/" << printThisVec[i].time_member().tm_mday
            << "/" << 1900 + (printThisVec[i].time_member().tm_year) << '\n';

        std::cout << "Time: " << printThisVec[i].time_member().tm_hour
            << ":" << printThisVec[i].time_member().tm_min
            << ":" << printThisVec[i].time_member().tm_sec << '\n';

        std::cout << "Time(sec): " << printThisVec[i].getWalkElapsedTimeSec() << '\n';

        std::cout << "Distance: " << printThisVec[i].getWalkDistance() << '\n';
        std::cout << '\n';
    }
}
