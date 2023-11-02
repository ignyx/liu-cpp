#include "Network.h"
#include "catch.hpp"

TEST_CASE("Connection : Initialize connection object") {
  Connection connection_a;
  Connection connection_b{5.0};

  CHECK(connection_a.potential == 0.0);
  CHECK(connection_b.potential == 5.0);
}

TEST_CASE("Component : get_voltage") {
  Connection connection_a{2.0};
  Connection connection_b{5.0};
  Component component_a = Component("component_a", connection_a, connection_a);
  Component component_b = Component("component_b", connection_a, connection_b);
  Component component_c = Component("component_c", connection_b, connection_a);

  CHECK(component_a.get_voltage() == 0.0);
  CHECK(component_b.get_voltage() == 3.0);
  CHECK(component_c.get_voltage() == -3.0);
}

TEST_CASE("Component : get_current") {
  Connection connection_a{2.0};
  Connection connection_b{5.0};
  Component component_a = Component("component_a", connection_a, connection_a);
  Component component_b = Component("component_b", connection_a, connection_b);
  Component component_c = Component("component_c", connection_b, connection_a);

  CHECK(component_a.get_current() == 0.0);
  CHECK(component_b.get_current() == 0.0);
  CHECK(component_c.get_current() == 0.0);
}

TEST_CASE("Component : get_name") {
  Connection connection_a{2.0};
  Connection connection_b{5.0};
  Component component_a = Component("component_a", connection_a, connection_a);
  Component component_b = Component("component_b", connection_a, connection_b);
  Component component_c = Component("component_c", connection_b, connection_a);

  CHECK(component_a.get_name() == "component_a");
  CHECK(component_b.get_name() == "component_b");
  CHECK(component_c.get_name() == "component_c");
}

// TEST_CASE("Component : run_step should do nothing") {
//   Connection connection_a{5.0};
//   Connection connection_b{2.0};
//   Component component = Component("component_a", connection_a, connection_a);
//
//   CHECK(component.get_voltage() == 3.0);
//   component.run_step(1.0);
//   CHECK(component.get_voltage() == 3.0);
// }
