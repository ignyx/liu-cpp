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

Time operator+(const Time &givenTime1, const int &t);

Time operator-(const Time &givenTime1, const int &t);

Time &operator++(Time &givenTime);

Time operator++(Time &givenTime, int);

Time &operator--(Time &givenTime);

Time operator--(Time &givenTime, int);

bool operator==(const Time &givenTime1, const Time &givenTime2);

bool operator!=(const Time &givenTime1, const Time &givenTime2);

bool operator<(const Time &givenTime1, const Time &givenTime2);

bool operator<=(const Time &givenTime1, const Time &givenTime2);

bool operator>(const Time &givenTime1, const Time &givenTime2);

bool operator>=(const Time &givenTime1, const Time &givenTime2);

bool is_valid(Time const &givenTime);

bool is_am(Time const &givenTime);

std::string to_string(Time const &givenTime, format timeFormat);

std::ostream &operator<<(std::ostream &os, Time const &givenTime);

std::istream &operator>>(istream &is, Time &newTime);

#endif
