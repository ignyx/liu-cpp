#include "Time.h"
#include "catch.hpp"

TEST_CASE("Time : Initialize Time struct") {
  Time time;
  CHECK(time.hours == 0);
  CHECK(time.minutes == 0);
  CHECK(time.seconds == 0);
}

TEST_CASE("Time operator== : comparing two Time objects") {
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
