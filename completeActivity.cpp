//  ActivityTracker
//  completeActivity.cpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.

#include "completeActivity.hpp"

bool completeActivity::parseDate(std::string dateStr) {
    // parse the string and assign a pointer to the parsed string
    char *rest = strptime(dateStr.c_str(), "%D", &m_time);
    if (rest == nullptr || *rest != '\0') { // are there unparsed characters left?
        m_date_is_valid = false; // parse failed
    } else {
        m_date_is_valid = true;  // else parse succeeded
    }
    return m_date_is_valid;
}

bool completeActivity::parseTime(std::string timeStr) {
    char *rest = strptime(timeStr.c_str(), "%T", &m_time);
    if (rest == nullptr || *rest != '\0') {
        m_time_is_valid = false;
    } else {
        m_time_is_valid = true;
    }
    return m_time_is_valid;
}
