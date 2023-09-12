#include "Time.h"
#include "catch.hpp"

TEST_CASE("Initialize Time struct") {
  Time time;
  CHECK(time.hours == 0);
  CHECK(time.minutes == 0);
  CHECK(time.seconds == 0);
}
