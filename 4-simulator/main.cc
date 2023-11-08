#include "Network.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main(){
  Network circuit1 {};
  Connection connection_1{0};
  Connection connection_2{0};
  Connection connection_3{0};
  Connection connection_4{0};
  circuit1.add_component(new Battery("Bat", 24.0, connection_4, connection_1));
  circuit1.add_component(new Resistor("R1", 6.0, connection_1, connection_2));
  circuit1.add_component(new Resistor("R2", 4.0, connection_2, connection_3));
  circuit1.add_component(new Resistor("R3", 8.0, connection_3, connection_4));
  circuit1.add_component(new Resistor("R4", 12.0, connection_2, connection_4));
  (circuit1.get_components()[1])->run_step(0.001);
  (circuit1.get_components()[1])->run_step(0.001);
  cout << (circuit1.get_components()[1])->get_current() << endl;
  circuit1.simulate(200000, 10, 0.01);
}