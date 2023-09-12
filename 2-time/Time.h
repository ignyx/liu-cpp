#ifdef TEST_H
#define TEST_H

enum format { USA, EUROPEAN };

struct Time {
  int seconds;
  int minutes;
  int hours;
};

Time operator+(const Time &givenTime1, const Time &givenTime2);

Time operator+(const Time &givenTime1, const int &t);

Time &operator++(Time &givenTime);

Time operator++(Time &givenTime, int);

bool operator==(const Time &givenTime1, const Time &givenTime2);

bool operator<(const Time &givenTime1, const Time &givenTime2);

bool operator<=(const Time &givenTime1, const Time &givenTime2);

bool operator>(const Time &givenTime1, const Time &givenTime2);

bool operator>=(const Time &givenTime1, const Time &givenTime2);

bool is_valid(Time &givenTime);

bool is_am(Time &givenTime);

string to_string(Time const &givenTime, format timeFormat);

ostream &operator<<(ostream &os, Time const &givenTime)

#endif
