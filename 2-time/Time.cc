#include "Time.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Time operator+(const Time &givenTime1, const int &t) {
  Time newTime;
  int seconds = (((givenTime1.seconds + givenTime1.minutes * 60 +
                   givenTime1.hours * 3600 + t) %
                  86400) +
                 86400) %
                86400;
  newTime.hours = seconds / 3600;
  seconds = seconds % 3600;
  newTime.minutes = seconds / 60;
  seconds = seconds % 60;
  newTime.seconds = seconds;
  return newTime;
}

Time operator+(const Time &givenTime1, const Time &givenTime2) {
  Time newTime;
  newTime = givenTime1 + (givenTime2.seconds + givenTime2.minutes * 60 +
                          givenTime2.hours * 3600);
  return newTime;
}

Time operator-(const Time &givenTime1, const int &t) {
  return givenTime1 + (-t);
}

Time &operator++(Time &givenTime) {
  givenTime = operator+(givenTime, 1);
  return givenTime;
}

Time operator++(Time &givenTime, int) {
  Time tmp{givenTime};
  ++givenTime;
  return tmp;
}

Time &operator--(Time &givenTime) {
  givenTime = givenTime - 1;
  return givenTime;
}

Time operator--(Time &givenTime, int) {
  Time tmp{givenTime};
  --givenTime;
  return tmp;
}

bool operator==(const Time &givenTime1, const Time &givenTime2) {
  return ((givenTime1.hours == givenTime2.hours) and
          (givenTime1.minutes == givenTime2.minutes) and
          (givenTime1.seconds == givenTime2.seconds));
}

bool operator!=(const Time &givenTime1, const Time &givenTime2) {
  return !(givenTime1 == givenTime2);
}

bool operator<(const Time &givenTime1, const Time &givenTime2) {
  if (givenTime1.hours < givenTime2.hours) {
    return true;
  } else if (givenTime1.hours == givenTime2.hours) {
    if (givenTime1.minutes < givenTime2.minutes) {
      return true;
    } else if (givenTime1.minutes == givenTime2.minutes) {
      return givenTime1.seconds < givenTime2.seconds;
    }
  }

  return false;
}

bool operator<=(const Time &givenTime1, const Time &givenTime2) {
  return (givenTime1 < givenTime2) or (givenTime1 == givenTime2);
}

bool operator>(const Time &givenTime1, const Time &givenTime2) {
  return !(givenTime1 <= givenTime2);
}

bool operator>=(const Time &givenTime1, const Time &givenTime2) {
  return !(givenTime1 < givenTime2);
}

bool is_valid(Time const &givenTime) {
  return (givenTime.hours >= 0 and givenTime.hours < 24) and
         (givenTime.minutes >= 0 and givenTime.minutes < 60) and
         (givenTime.seconds >= 0 and givenTime.seconds < 60);
}

bool is_am(Time const &givenTime) {
  if (givenTime.hours >= 12) {
    return false;
  }
  return true;
}

string fill_two_decimals(int decimal) {
  string decimalString = to_string(decimal);
  if (decimalString.length() >= 2) {
    return decimalString;
  } else {
    decimalString = "0" + decimalString;
    return decimalString;
  }
}

string to_string(Time const &givenTime, format timeFormat) {
  string timeString;
  if (timeFormat == USA) {
    if (is_am(givenTime)) {
      timeString = fill_two_decimals((givenTime.hours + 11) % 12 + 1) + ":" +
                   fill_two_decimals(givenTime.minutes) + ":" +
                   fill_two_decimals(givenTime.seconds) + " AM";
    } else {
      timeString = fill_two_decimals((givenTime.hours + 11) % 12 + 1) + ":" +
                   fill_two_decimals(givenTime.minutes) + ":" +
                   fill_two_decimals(givenTime.seconds) + " PM";
    }

  } else {
    timeString = fill_two_decimals(givenTime.hours) + ":" +
                 fill_two_decimals(givenTime.minutes) + ":" +
                 fill_two_decimals(givenTime.seconds);
  }

  return timeString;
}

ostream &operator<<(ostream &os, Time const &givenTime) {
  os << to_string(givenTime, EUROPEAN) << endl;
  return os;
}
