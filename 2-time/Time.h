#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

// USA : 12 hours format / EUROPEAN : 24 hours format
enum format { USA, EUROPEAN };

struct Time {
  int hours = 0;
  int minutes = 0;
  int seconds = 0;
};

Time operator+(const Time &givenTime1, const Time &givenTime2);

/**
 *  Adds t seconds to a given time
 */
Time operator+(const Time &givenTime1, const int &t);

/**
 *  Substracts t seconds from a given time
 */
Time operator-(const Time &givenTime1, const int &t);

/**
 *  Adds 1 seconds to a given time, returns previous value
 */
Time &operator++(Time &givenTime);

/**
 *  Adds 1 seconds to a given time, returns new value
 */
Time operator++(Time &givenTime, int);

/**
 *  Substracts 1 seconds from a given time, returns previous value
 */
Time &operator--(Time &givenTime);

/**
 *  Substracts 1 seconds from a given time, returns new value
 */
Time operator--(Time &givenTime, int);

bool operator==(const Time &givenTime1, const Time &givenTime2);

bool operator!=(const Time &givenTime1, const Time &givenTime2);

bool operator<(const Time &givenTime1, const Time &givenTime2);

bool operator<=(const Time &givenTime1, const Time &givenTime2);

bool operator>(const Time &givenTime1, const Time &givenTime2);

bool operator>=(const Time &givenTime1, const Time &givenTime2);

/**
 *  Verifies whether the values are within a positive 24h range
 */
bool is_valid(Time const &givenTime);

/**
 *  Returns true if in the morning. Note that midnight is AM, but noon is PM
 */
bool is_am(Time const &givenTime);

/**
 *  Returns a string formatted as "HH:MM:SS" (EUROPEAN) or "HH:MM:SS *M" (USA)
 */
std::string to_string(Time const &givenTime, format timeFormat);

std::ostream &operator<<(std::ostream &os, Time const &givenTime);

std::istream &operator>>(std::istream &is, Time &newTime);

#endif
