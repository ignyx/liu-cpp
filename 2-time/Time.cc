#include "Time.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Time operator+(const Time &given_time_1, const int &t) {
  Time new_time;
  int seconds = (((given_time_1.seconds + given_time_1.minutes * 60 +
                   given_time_1.hours * 3600 + t) %
                  86400) +
                 86400) %
                86400;
  new_time.hours = seconds / 3600;
  seconds = seconds % 3600;
  new_time.minutes = seconds / 60;
  seconds = seconds % 60;
  new_time.seconds = seconds;
  return new_time;
}

Time operator+(const Time &given_time_1, const Time &given_time_2) {
  Time new_time;
  new_time = given_time_1 + (given_time_2.seconds + given_time_2.minutes * 60 +
                             given_time_2.hours * 3600);
  return new_time;
}

Time operator-(const Time &given_time_1, const int &t) {
  return given_time_1 + (-t);
}

Time &operator++(Time &given_time) {
  given_time = operator+(given_time, 1);
  return given_time;
}

Time operator++(Time &given_time, int) {
  Time tmp{given_time};
  ++given_time;
  return tmp;
}

Time &operator--(Time &given_time) {
  given_time = given_time - 1;
  return given_time;
}

Time operator--(Time &given_time, int) {
  Time tmp{given_time};
  --given_time;
  return tmp;
}

bool operator==(const Time &given_time_1, const Time &given_time_2) {
  return ((given_time_1.hours == given_time_2.hours) and
          (given_time_1.minutes == given_time_2.minutes) and
          (given_time_1.seconds == given_time_2.seconds));
}

bool operator!=(const Time &given_time_1, const Time &given_time_2) {
  return !(given_time_1 == given_time_2);
}

bool operator<(const Time &given_time_1, const Time &given_time_2) {
  if (given_time_1.hours < given_time_2.hours) {
    return true;
  } else if (given_time_1.hours == given_time_2.hours) {
    if (given_time_1.minutes < given_time_2.minutes) {
      return true;
    } else if (given_time_1.minutes == given_time_2.minutes) {
      return given_time_1.seconds < given_time_2.seconds;
    }
  }

  return false;
}

bool operator<=(const Time &given_time_1, const Time &given_time_2) {
  return (given_time_1 < given_time_2) or (given_time_1 == given_time_2);
}

bool operator>(const Time &given_time_1, const Time &given_time_2) {
  return !(given_time_1 <= given_time_2);
}

bool operator>=(const Time &given_time_1, const Time &given_time_2) {
  return !(given_time_1 < given_time_2);
}

bool is_valid(Time const &given_time) {
  return (given_time.hours >= 0 and given_time.hours < 24) and
         (given_time.minutes >= 0 and given_time.minutes < 60) and
         (given_time.seconds >= 0 and given_time.seconds < 60);
}

bool is_am(Time const &given_time) {
  if (given_time.hours >= 12) {
    return false;
  }
  return true;
}

string fill_two_decimals(int decimal) {
  string decimal_string = to_string(decimal);
  if (decimal_string.length() >= 2) {
    return decimal_string;
  } else {
    decimal_string = "0" + decimal_string;
    return decimal_string;
  }
}

string to_string(Time const &given_time, format time_format) {
  string time_string;
  if (time_format == USA) {
    if (is_am(given_time)) {
      time_string = fill_two_decimals((given_time.hours + 11) % 12 + 1) + ":" +
                    fill_two_decimals(given_time.minutes) + ":" +
                    fill_two_decimals(given_time.seconds) + " AM";
    } else {
      time_string = fill_two_decimals((given_time.hours + 11) % 12 + 1) + ":" +
                    fill_two_decimals(given_time.minutes) + ":" +
                    fill_two_decimals(given_time.seconds) + " PM";
    }

  } else {
    time_string = fill_two_decimals(given_time.hours) + ":" +
                  fill_two_decimals(given_time.minutes) + ":" +
                  fill_two_decimals(given_time.seconds);
  }

  return time_string;
}

ostream &operator<<(ostream &os, Time const &given_time) {
  os << to_string(given_time, EUROPEAN);
  return os;
}

istream &operator>>(istream &is, Time &new_time) {
  char character;
  char number_chars[2];
  int index{0};
  bool failed{false};

  while (is >> character and !failed and index < 8) {
    int relative_index = index % 3; // index in number_chars
    cout << index << character << relative_index << endl;
    if (isdigit(character)) {
      if (relative_index > 1) // 3rd digit !
        failed = true;
      else
        number_chars[relative_index] = character;
    } else if (character == ':' and
               relative_index == 2) { // column in right position
      if (index == 2)
        new_time.hours = atoi(number_chars);
      else // index == 5
        new_time.minutes = atoi(number_chars);
      // seconds dealt with after loop
    } else
      failed = true;
    index++;
  }
  if (!failed)
    new_time.seconds = atoi(number_chars);
  if (!failed)
    cout << "sucess :thinking" << endl;

  cout << new_time;

  if (failed or !is_valid(new_time)) {
    cout << is_valid(new_time);
    new_time = {0, 0, 0};
    is.setstate(ios_base::failbit);
  }

  return is;
}
