//  ActivityTracker
//  completeActivity.hpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.

#ifndef completeWalk_hpp
#define completeWalk_hpp

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

class completeActivity {

public:
    completeActivity(std::string n, std::string d, std::string t, double dist)
    : m_walkName(n), m_walkDate(d), m_walkElapsedTime(t), m_walkDistance(dist),
        m_time_is_valid(false), m_date_is_valid(false)
        { std::memset(&m_time, 0, sizeof(m_time)); }

    std::string getWalkName() const { return m_walkName; };
    const struct tm time_member() const { return m_time; };
    double getWalkDistance() const { return m_walkDistance; };
    int getWalkElapsedTimeSec() const { return m_elapsedTimeSec; };

    void setActivityElapsedTime(int time) { m_elapsedTimeSec = time; };
    bool isTimeValid() const { return m_time_is_valid; }
    bool isDateValid() const { return m_date_is_valid; }
    bool parseTime(std::string timeStr);
    bool parseDate(std::string dateStr);

	// sort that sorts first by name then by time if the names are equal
	// this is needed in order to store these objects in a set, these are the 'rules' to order 
	bool operator< (const completeActivity & other) const {
		return m_walkName < other.m_walkName
			|| (m_walkName == other.m_walkName && m_elapsedTimeSec < other.m_elapsedTimeSec);
	}


private:
    struct tm m_time;
    std::string m_walkName;
    std::string m_walkDate;
    std::string m_walkElapsedTime;
    double m_walkDistance = 0.0;
    bool m_time_is_valid;
    bool m_date_is_valid;
    int m_elapsedTimeSec;

};


#endif /* completeWalk_hpp */
