#include "Time.h"
#include "catch.hpp"

TEST_CASE("Time : Initialize Time struct") {
  Time time;
  CHECK(time.hours == 0);
  CHECK(time.minutes == 0);
  CHECK(time.seconds == 0);
}

TEST_CASE("Time operator== : equality between two Time objects") {
  Time time_a, time_b;

  CHECK(time_a == time_b);
  CHECK(time_b == time_a);

  time_a.seconds = 1;
  CHECK_FALSE(time_a == time_b);
  CHECK_FALSE(time_b == time_a);

  time_b.seconds = 1;
  CHECK(time_a == time_b);
  CHECK(time_b == time_a);

  time_a.minutes = 35;
  CHECK_FALSE(time_a == time_b);
  CHECK_FALSE(time_b == time_a);

  time_b.minutes = 35;
  CHECK(time_a == time_b);
  CHECK(time_b == time_a);

  time_a = {1, 2, 3};
  CHECK_FALSE(time_a == time_b);
  CHECK_FALSE(time_b == time_a);

  time_b = {1, 2, 3};
  CHECK(time_a == time_b);
  CHECK(time_b == time_a);
}

TEST_CASE("Time operator+ : adding two Time objects") {
  Time time_a, time_b, time_c;

  CHECK(time_a + time_b == time_c);
  CHECK(time_a + time_b == time_b + time_a);

  time_a = {1, 2, 3};
  CHECK(time_a + time_b == time_a);
  CHECK(time_a + time_b == time_b + time_a);

  time_b = {3, 2, 1};
  time_c = {4, 4, 4};
  CHECK(time_a + time_b == time_c);
  CHECK(time_a + time_b == time_b + time_a);

  time_a = {0, 0, 30};
  time_c = {0, 1, 0};
  CHECK(time_a + time_a == time_c);

  time_a = {0, 0, 59};
  time_b = {0, 0, 1};
  time_c = {0, 1, 0};
  CHECK(time_a + time_b == time_c);

  time_a = {23, 59, 59};
  time_b = {0, 0, 1};
  time_c = {0, 0, 0};
  CHECK(time_a + time_b == time_c);

  time_a = {23, 55, 59};
  time_b = {10, 10, 1};
  time_c = {10, 6, 0};
  CHECK(time_a + time_b == time_c);
}

TEST_CASE("Time operator+ : adding a Time object and an int") {
  Time time_a, time_b;

  CHECK(time_a + 0 == time_a);

  time_b = {0, 0, 59};
  CHECK(time_a + 59 == time_b);

  time_b = {23, 59, 57};
  CHECK(time_a + 86397 == time_b);
  CHECK(time_a + (-3) == time_b);

  time_a = {2, 59, 59};
  time_b = {3, 0, 0};
  CHECK(time_a + 1 == time_b);
  CHECK(time_b + (-1) == time_a);

  CHECK(time_a + (-86400) == time_a);
}

TEST_CASE("Time operator- : substracting an int to a Time object") {
  Time time_a, time_b;

  CHECK(time_a - 0 == time_a);

  time_b = {0, 0, 59};
  CHECK(time_b - 59 == time_a);

  time_b = {23, 59, 57};
  CHECK(time_b - 86397 == time_a);
  CHECK(time_b - (-3) == time_a);

  time_a = {2, 59, 59};
  time_b = {3, 0, 0};
  CHECK(time_b - 1 == time_a);
  CHECK(time_a - (-1) == time_b);

  CHECK(time_b - (-86400) == time_b);
}

TEST_CASE("Time operator++ : incrementing a Time object") {
  Time time_a, time_b;

  CHECK(time_a++ == time_b);
  CHECK(time_a == time_b + 1);

  time_a = {2, 59, 59};
  time_b = time_a;
  CHECK(time_a++ == time_b);
  CHECK(time_a == time_b + 1);

  time_a = {23, 59, 59};
  time_b = time_a;
  CHECK(time_a++ == time_b);
  CHECK(time_a == time_b + 1);
}

TEST_CASE("Time ++operator : incrementing a Time object") {
  Time time_a, time_b;

  CHECK_FALSE(++time_a == time_b);
  CHECK(time_a == time_b + 1);

  time_a = {2, 59, 59};
  time_b = time_a;
  CHECK_FALSE(++time_a == time_b);
  CHECK(time_a == time_b + 1);

  time_a = {23, 59, 59};
  time_b = time_a;
  CHECK_FALSE(++time_a == time_b);
  CHECK(time_a == time_b + 1);
}

TEST_CASE("Time operator-- : decrementing a Time object") {
  Time time_a, time_b;

  CHECK(time_a-- == time_b);
  CHECK(time_a == time_b - 1);

  time_a = {2, 59, 59};
  time_b = time_a;
  CHECK(time_a-- == time_b);
  CHECK(time_a == time_b - 1);

  time_a = {23, 59, 59};
  time_b = time_a;
  CHECK(time_a-- == time_b);
  CHECK(time_a == time_b - 1);
}

TEST_CASE("Time --operator : decrementing a Time object") {
  Time time_a, time_b;

  CHECK_FALSE(--time_a == time_b);
  CHECK(time_a == time_b - 1);

  time_a = {2, 59, 59};
  time_b = time_a;
  CHECK_FALSE(--time_a == time_b);
  CHECK(time_a == time_b - 1);

  time_a = {23, 59, 59};
  time_b = time_a;
  CHECK_FALSE(--time_a == time_b);
  CHECK(time_a == time_b - 1);
}

TEST_CASE("Time operator!= : inequality between two Time objects") {
  Time time_a, time_b;

  CHECK_FALSE(time_a != time_b);
  CHECK_FALSE(time_b != time_a);

  time_a = {0, 0, 1};
  CHECK(time_a != time_b);
  CHECK(time_b != time_a);

  time_b = time_a;
  CHECK_FALSE(time_a != time_b);
  CHECK_FALSE(time_b != time_a);

  time_a = {2, 38, 45};
  time_b = {2, 37, 45};
  CHECK(time_a != time_b);
  CHECK(time_b != time_a);

  time_a = {3, 37, 45};
  time_b = {2, 37, 45};
  CHECK(time_a != time_b);
  CHECK(time_b != time_a);

  time_a = {2, 37, 46};
  time_b = {2, 37, 45};
  CHECK(time_a != time_b);
  CHECK(time_b != time_a);
}

TEST_CASE("Time operator< : comparison between Time objects") {
  Time time_a, time_b;

  CHECK_FALSE(time_a < time_b);
  CHECK_FALSE(time_b < time_a);

  time_a = {0, 0, 1};
  CHECK_FALSE(time_a < time_b);
  CHECK(time_b < time_a);

  time_b = time_a;
  CHECK_FALSE(time_a < time_b);
  CHECK_FALSE(time_b < time_a);

  time_a = {2, 38, 45};
  time_b = {2, 37, 45};
  CHECK_FALSE(time_a < time_b);
  CHECK(time_b < time_a);

  time_a = {3, 37, 45};
  time_b = {2, 37, 45};
  CHECK_FALSE(time_a < time_b);
  CHECK(time_b < time_a);

  time_a = {2, 37, 46};
  time_b = {2, 37, 45};
  CHECK_FALSE(time_a < time_b);
  CHECK(time_b < time_a);
}

TEST_CASE("Time operator<= : comparison between Time objects") {
  Time time_a, time_b;

  CHECK(time_a <= time_b);
  CHECK(time_b <= time_a);

  time_a = {0, 0, 1};
  CHECK_FALSE(time_a <= time_b);
  CHECK(time_b <= time_a);

  time_b = time_a;
  CHECK(time_a <= time_b);
  CHECK(time_b <= time_a);

  time_a = {2, 38, 45};
  time_b = {2, 37, 45};
  CHECK_FALSE(time_a <= time_b);
  CHECK(time_b <= time_a);

  time_a = {3, 37, 45};
  time_b = {2, 37, 45};
  CHECK_FALSE(time_a <= time_b);
  CHECK(time_b <= time_a);

  time_a = {2, 37, 46};
  time_b = {2, 37, 45};
  CHECK_FALSE(time_a <= time_b);
  CHECK(time_b <= time_a);
}

TEST_CASE("Time operator> : comparison between Time objects") {
  Time time_a, time_b;

  CHECK_FALSE(time_a > time_b);
  CHECK_FALSE(time_b > time_a);

  time_a = {0, 0, 1};
  CHECK(time_a > time_b);
  CHECK_FALSE(time_b > time_a);

  time_b = time_a;
  CHECK_FALSE(time_a > time_b);
  CHECK_FALSE(time_b > time_a);

  time_a = {2, 38, 45};
  time_b = {2, 37, 45};
  CHECK(time_a > time_b);
  CHECK_FALSE(time_b > time_a);

  time_a = {3, 37, 45};
  time_b = {2, 37, 45};
  CHECK(time_a > time_b);
  CHECK_FALSE(time_b > time_a);

  time_a = {2, 37, 46};
  time_b = {2, 37, 45};
  CHECK(time_a > time_b);
  CHECK_FALSE(time_b > time_a);
}

TEST_CASE("Time operator>= : comparison between Time objects") {
  Time time_a, time_b;

  CHECK(time_a >= time_b);
  CHECK(time_b >= time_a);

  time_a = {0, 0, 1};
  CHECK(time_a >= time_b);
  CHECK_FALSE(time_b >= time_a);

  time_b = time_a;
  CHECK(time_a >= time_b);
  CHECK(time_b >= time_a);

  time_a = {2, 38, 45};
  time_b = {2, 37, 45};
  CHECK(time_a >= time_b);
  CHECK_FALSE(time_b >= time_a);

  time_a = {3, 37, 45};
  time_b = {2, 37, 45};
  CHECK(time_a >= time_b);
  CHECK_FALSE(time_b >= time_a);

  time_a = {2, 37, 46};
  time_b = {2, 37, 45};
  CHECK(time_a >= time_b);
  CHECK_FALSE(time_b >= time_a);
}

TEST_CASE("Time is_valid : valid values") {
  Time time_a;

  CHECK(is_valid(time_a));

  time_a = {0, 0, 1};
  CHECK(is_valid(time_a));

  time_a = {0, 0, -1};
  CHECK_FALSE(is_valid(time_a));

  time_a = {0, 0, 60};
  CHECK_FALSE(is_valid(time_a));

  time_a = {0, -1, 59};
  CHECK_FALSE(is_valid(time_a));

  time_a = {0, 60, 0};
  CHECK_FALSE(is_valid(time_a));

  time_a = {-1, 59, 59};
  CHECK_FALSE(is_valid(time_a));

  time_a = {24, 0, 0};
  CHECK_FALSE(is_valid(time_a));

  time_a = {23, 59, 59};
  CHECK(is_valid(time_a));
}

TEST_CASE("Time is_am : ante / post meridian") {
  Time time_a;

  CHECK(is_am(time_a));

  time_a = {0, 0, 1};
  CHECK(is_am(time_a));

  time_a = {11, 59, 59};
  CHECK(is_am(time_a));

  time_a = {12, 0, 0};
  CHECK_FALSE(is_am(time_a));

  time_a = {12, 0, 1};
  CHECK_FALSE(is_am(time_a));

  time_a = {23, 59, 59};
  CHECK_FALSE(is_am(time_a));
}

TEST_CASE("Time to_string : display time") {
  Time time_a;

  CHECK(to_string(time_a, USA) == "12:00:00 AM");

  time_a = {0, 0, 1};
  CHECK(to_string(time_a, USA) == "12:00:01 AM");

  time_a = {11, 59, 59};
  CHECK(to_string(time_a, USA) == "11:59:59 AM");

  time_a = {12, 0, 0};
  CHECK(to_string(time_a, USA) == "12:00:00 PM");

  time_a = {12, 0, 1};
  CHECK(to_string(time_a, USA) == "12:00:01 PM");

  time_a = {23, 59, 59};
  CHECK(to_string(time_a, USA) == "11:59:59 PM");

  time_a = {0, 0, 0};
  CHECK(to_string(time_a, EUROPEAN) == "00:00:00");

  time_a = {0, 0, 1};
  CHECK(to_string(time_a, EUROPEAN) == "00:00:01");

  time_a = {11, 59, 59};
  CHECK(to_string(time_a, EUROPEAN) == "11:59:59");

  time_a = {12, 0, 0};
  CHECK(to_string(time_a, EUROPEAN) == "12:00:00");

  time_a = {12, 0, 1};
  CHECK(to_string(time_a, EUROPEAN) == "12:00:01");

  time_a = {23, 59, 59};
  CHECK(to_string(time_a, EUROPEAN) == "23:59:59");
}
/fake cin
TEST_CASE("Time to_string : display time") {
  std::istringstreamiss{"12 19 8"};
  Time time_a{}; 
  iss>>time_a; 
  CHECK_FALSE(iss.fail());
  CHECK(to_string(z)=="12:19:08", EUROPEAN);

  std::istringstreamiss{"0 1 2 3 4"};
  iss>>time_a; 
  CHECK_FALSE(iss.fail());
  CHECK(to_string(z)=="00:01:02", EUROPEAN);


  std::istringstreamiss{"0 -19 8"};
  iss>>time_a; 
  CHECK(iss.fail());
CHECK_FAIL(to_string(time_a)=="00:-19:08", EUROPEAN);


//fake cout
std::ostringstreamoss{};
Time time_a{13 7 59};
oss<<time_a<<endl; 
CHECK(oss.str()=="13:07:59");


