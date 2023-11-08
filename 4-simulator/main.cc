#include "Network.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void simulate_circuit1(unsigned int iterations, unsigned int lines,
                       double time_step);
void simulate_circuit2(unsigned int iterations, unsigned int lines,
                       double time_step);
void simulate_circuit3(unsigned int iterations, unsigned int lines,
                       double time_step);

int main() {
  simulate_circuit1(200000, 10, 0.01);
  simulate_circuit2(200000, 10, 0.01);
  simulate_circuit3(200000, 10, 0.01);
}

void simulate_circuit1(unsigned int iterations, unsigned int lines,
                       double time_step) {
  Network circuit1{};
  Connection connection_1{0};
  Connection connection_2{0};
  Connection connection_3{0};
  Connection connection_4{0};
  circuit1.add_component(new Battery("Bat", 24.0, connection_4, connection_1));
  circuit1.add_component(new Resistor("R1", 6.0, connection_1, connection_2));
  circuit1.add_component(new Resistor("R2", 4.0, connection_2, connection_3));
  circuit1.add_component(new Resistor("R3", 8.0, connection_3, connection_4));
  circuit1.add_component(new Resistor("R4", 12.0, connection_2, connection_4));
  circuit1.simulate(iterations, lines, time_step);
  // TODO delete
}

void simulate_circuit2(unsigned int iterations, unsigned int lines,
                       double time_step) {
  Network circuit2{};
  Connection connection_1{0};
  Connection connection_2{0};
  Connection connection_3{0};
  Connection connection_4{0};
  circuit2.add_component(new Battery("Bat", 24.0, connection_4, connection_1));
  circuit2.add_component(new Resistor("R1", 150.0, connection_1, connection_2));
  circuit2.add_component(new Resistor("R2", 50.0, connection_1, connection_3));
  circuit2.add_component(new Resistor("R3", 100.0, connection_2, connection_3));
  circuit2.add_component(new Resistor("R4", 300.0, connection_2, connection_4));
  circuit2.add_component(new Resistor("R5", 250.0, connection_3, connection_4));
  circuit2.simulate(iterations, lines, time_step);
  // TODO delete
}
void simulate_circuit3(unsigned int iterations, unsigned int lines,
                       double time_step) {
  Network circuit3{};
  Connection connection_1{0};
  Connection connection_2{0};
  Connection connection_3{0};
  Connection connection_4{0};
  circuit3.add_component(new Battery("Bat", 24.0, connection_4, connection_1));
  circuit3.add_component(new Resistor("R1", 150.0, connection_1, connection_2));
  circuit3.add_component(new Resistor("R2", 50.0, connection_1, connection_3));
  circuit3.add_component(new Capacitor("C3", 1.0, connection_2, connection_3));
  circuit3.add_component(new Resistor("R4", 300.0, connection_2, connection_4));
  circuit3.add_component(new Capacitor("C5", 0.75, connection_3, connection_4));
  circuit3.simulate(iterations, lines, time_step);
  // TODO delete
}
