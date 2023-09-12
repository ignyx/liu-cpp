#include "Time.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Time operator+(const Time &givenTime1, const Time &givenTime2) {
  Time newTime;
  int rest;
  newTime.seconds = (givenTime1.seconds + givenTime2.seconds) % 60;
  rest = (givenTime1.seconds + givenTime2.seconds) / 60;
  newTime.minutes = (givenTime1.minutes + givenTime2.minutes + rest) % 60;
  rest = (givenTime1.minutes + givenTime2.minutes + rest) / 60;
  newTime.hours = (givenTime1.hours + givenTime2.hours + rest) % 24;
  return newTime;
}

Time operator+(const Time &givenTime1, const int &t) {
  Time newTime;
  int rest;
  newTime.seconds = (givenTime1.seconds + t) % 60;
  rest = (givenTime1.seconds + t) / 60;
  newTime.minutes = (givenTime1.minutes + rest) % 60;
  rest = (givenTime1.minutes + rest) / 60;
  newTime.hours = (givenTime1.hours + rest) % 24;
  return newTime;
}

Time operator-(const Time &givenTime1, const int &t) {
  Time newTime;
  int rest{0};
  newTime.seconds = (givenTime1.seconds - t) % 60;
  if ((givenTime1.seconds - t) < 0) {
    rest = 1;
  }
  newTime.minutes = (givenTime1.minutes - rest) % 60;
  rest = 0;
  if ((givenTime1.minutes - t) < 0) {
    rest = 1;
  }
  newTime.hours = (givenTime1.hours - rest) % 24;
  return newTime;
}

Time &operator++(Time &givenTime) {
  Time unit{1, 0, 0};
  givenTime = operator+(givenTime, unit);
  return givenTime;
}

Time operator++(Time &givenTime, int) {
  Time tmp{givenTime};
  ++givenTime;
  return tmp;
}

bool operator==(const Time &givenTime1, const Time &givenTime2) {
  if ((givenTime1.hours == givenTime2.hours) and
      (givenTime1.minutes == givenTime2.minutes) and
      (givenTime1.seconds == givenTime2.seconds)) {
    return true;
  } else {
    return false;
  }
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
  if ((givenTime1 < givenTime2) or (givenTime1 == givenTime2)) {
    return true;
  } else {
    return false;
  }
}

bool operator>(const Time &givenTime1, const Time &givenTime2) {
  return operator<=(givenTime2, givenTime1);
}

bool operator>=(const Time &givenTime1, const Time &givenTime2) {
  return operator<(givenTime2, givenTime1);
}

bool is_valid(Time &givenTime) {
  bool timeValidity = true;
  if (givenTime.seconds < 0 or givenTime.seconds >= 60) {
    cout << "Unvalid seconds" << endl;
    timeValidity = false;
  }
  if (givenTime.minutes < 0 or givenTime.minutes >= 60) {
    cout << "Unvalid minutes" << endl;
    timeValidity = false;
  }
  if (givenTime.hours < 0 or givenTime.hours >= 24) {
    cout << "Unvalid hours" << endl;
    timeValidity = false;
  }
  return timeValidity;
}

bool is_am(Time const &givenTime) {
  if (givenTime.hours >= 12) {
    cout << "PM hour" << endl;
    return false;
  }
  cout << "AM hour" << endl;
  return true;
}

string fill_two_decimals(int decimal) {
  string decimalString = to_string(decimal);
  if (decimalString.length() >= 2) {
    return decimalString;
  } else {
    decimalString = "0" + decimalString;
  }
  return decimalString;
}

string to_string(Time const &givenTime, format timeFormat) {
  string timeString;
  if (timeFormat == USA) {
    if (is_am(givenTime)) {
      timeString = fill_two_decimals((givenTime.hours) % 12) + ":" +
                   fill_two_decimals(givenTime.minutes) + ":" +
                   fill_two_decimals(givenTime.seconds) + " AM";
    } else {
      timeString = fill_two_decimals((givenTime.hours) % 12) + ":" +
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
