//  ActivityTracker
//  fillActivityVector.cpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.

#include <stdexcept>
#include <iostream>
#include <vector>
#include <ctime>

#include "fillActivityVector.hpp"
#include "completeActivity.hpp"

double doubleFromString(const std::string& str) {
    char *endptr = nullptr;
    double result = strtof(str.c_str(), &endptr);

    if (*endptr != 0) {
        char problem[100];
        sprintf(problem, "Error in float at position %ld", (endptr - str.c_str()) );
        throw std::invalid_argument(problem);
    }
	return result;
}

void fillActivityVector(std::vector<completeActivity>& fillAllActivities) {
    std::string activityName, activityDate, activityElapsedTime, activityDistance;
    double str2doubleDist = 0.0;
    int activityElapsedTimeSec = 0;

    while(true) {
        std::cout << '\n';
        std::cout << "Enter walk name (no spaces), Type 'exit' in name when finished.\n> ";
        std::cin >> activityName;
            if(activityName == "exit") break;
        std::cout << "Enter date:\n> "; std::cin >> activityDate;
        std::cout << "Enter time:\n> "; std::cin >> activityElapsedTime;

        std::cout << "Enter the walk distance in miles \n> "; std::cin >> activityDistance;
        try {
            str2doubleDist = doubleFromString(activityDistance);
        } catch (std::exception exception) {
            std::cout << '\n' << activityDistance << " " << "failed to convert to double: "
            << exception.what() << std::endl; std::cout << "Please re-enter walk.\n\n";
            continue;
        }

        // create an object
        completeActivity newActivity(activityName, activityDate, activityElapsedTime, str2doubleDist);

        // parse input and check input for date and time correctness
        newActivity.parseDate(activityDate);
        if (newActivity.isDateValid() == false) {
            std::cout << "\nDate string was not valid. Please re-enter walk.\n" << std::endl;
            continue;
        }
        newActivity.parseTime(activityElapsedTime);
        if (newActivity.isTimeValid() == false) {
            std::cout << "\nTime string was not valid. Please re-enter walk.\n" << std::endl;
            continue;
        }

        // convert time into seconds for ease in sorting
        activityElapsedTimeSec = (newActivity.time_member().tm_hour * 3600) +
            (newActivity.time_member().tm_min * 60) + (newActivity.time_member().tm_sec);
        newActivity.setActivityElapsedTime(activityElapsedTimeSec);

        // input verified, save object in vector and output success
        fillAllActivities.push_back(newActivity);
		std::cout << "\nActivity successfully saved.\n";
    }
    std::cout << '\n';
}
