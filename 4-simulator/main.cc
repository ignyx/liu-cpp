#include "Network.h"
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using namespace std;

void print_help(char *arg0);
void parse_arguments(char **argv, int &iterations, int &lines,
                     double &time_step, double &battery_voltage);
void simulate_circuit1(const unsigned int iterations, const unsigned int lines,
                       const double time_step, const double battery_voltage);
void simulate_circuit2(const unsigned int iterations, const unsigned int lines,
                       const double time_step, const double battery_voltage);
void simulate_circuit3(const unsigned int iterations, const unsigned int lines,
                       const double time_step, const double battery_voltage);

int main(int argc, char **argv) {
  if (argc != 5) {
    print_help(argv[0]);
    exit(1);
  }

  int iterations, lines;
  double time_step, battery_voltage;

  parse_arguments(argv, iterations, lines, time_step, battery_voltage);

  simulate_circuit1(iterations, lines, time_step, battery_voltage);
  simulate_circuit2(iterations, lines, time_step, battery_voltage);
  simulate_circuit3(iterations, lines, time_step, battery_voltage);
}

void print_help(char *arg0) {
  cout << "usage: " << arg0 << " iterations lines step battery_voltage\n"
       << "example: " << arg0 << " 200000 10 0.01 24" << endl;
}

void parse_arguments(char **argv, int &iterations, int &lines,
                     double &time_step, double &battery_voltage) {
  try {
    iterations = stoi(argv[1]);
  } catch (invalid_argument const &) {
    cout << "Failed to parse iterations : \"" << argv[1]
         << "\" is not an integer." << endl;
    exit(1);
  } catch (out_of_range const &) {
    cout << "Failed to parse iterations : \"" << argv[1] << "\" is too big."
         << endl;
    exit(1);
  }

  try {
    lines = stoi(argv[2]);
  } catch (invalid_argument const &) {
    cout << "Failed to parse lines : \"" << argv[2] << "\" is not an integer."
         << endl;
    exit(1);
  } catch (out_of_range const &) {
    cout << "Failed to parse lines : \"" << argv[2] << "\" is too big." << endl;
    exit(1);
  }

  try {
    time_step = stod(argv[3]);
  } catch (invalid_argument const &) {
    cout << "Failed to parse time_step : \"" << argv[3] << "\" is not a double."
         << endl;
    exit(1);
  } catch (out_of_range const &) {
    cout << "Failed to parse time_step : \"" << argv[3] << "\" is too big."
         << endl;
    exit(1);
  }

  try {
    battery_voltage = stod(argv[4]);
  } catch (invalid_argument const &) {
    cout << "Failed to parse battery_voltage : \"" << argv[4]
         << "\" is not a double." << endl;
    exit(1);
  } catch (out_of_range const &) {
    cout << "Failed to parse battery_voltage : \"" << argv[4]
         << "\" is too big." << endl;
    exit(1);
  }

  if (iterations <= 0) {
    cout << "Please enter a positive number of iterations." << endl;
    exit(1);
  } else if (lines <= 0) {
    cout << "Please enter a positive number of displayed lines." << endl;
    exit(1);
  } else if (time_step <= 0) {
    cout << "Please enter a positive time step." << endl;
    exit(1);
  } else if (battery_voltage <= 0) {
    cout << "Please enter a positive battery_voltage." << endl;
    exit(1);
  } else if (lines > iterations) {
    cout << "Please enter a number of iterations greater than the number of "
            "lines."
         << endl;
    exit(1);
  }
}

void simulate_circuit1(const unsigned int iterations, const unsigned int lines,
                       const double time_step, const double battery_voltage) {
  Network circuit1{};
  Connection connection_1{0};
  Connection connection_2{0};
  Connection connection_3{0};
  Connection connection_4{0};
  circuit1.add_component(std::make_unique<Battery>(
      Battery("Bat", battery_voltage, connection_4, connection_1)));
  circuit1.add_component(std::make_unique<Resistor>(
      Resistor("R1", 6.0, connection_2, connection_1)));
  circuit1.add_component(std::make_unique<Resistor>(
      Resistor("R2", 4.0, connection_3, connection_2)));
  circuit1.add_component(std::make_unique<Resistor>(
      Resistor("R3", 8.0, connection_4, connection_3)));
  circuit1.add_component(std::make_unique<Resistor>(
      Resistor("R4", 12.0, connection_4, connection_2)));
  circuit1.simulate(iterations, lines, time_step);
}

void simulate_circuit2(const unsigned int iterations, const unsigned int lines,
                       const double time_step, const double battery_voltage) {
  Network circuit2{};
  Connection connection_1{0};
  Connection connection_2{0};
  Connection connection_3{0};
  Connection connection_4{0};
  circuit2.add_component(std::make_unique<Battery>(
      Battery("Bat", battery_voltage, connection_4, connection_1)));
  circuit2.add_component(std::make_unique<Resistor>(
      Resistor("R1", 150.0, connection_2, connection_1)));
  circuit2.add_component(std::make_unique<Resistor>(
      Resistor("R2", 50.0, connection_3, connection_1)));
  circuit2.add_component(std::make_unique<Resistor>(
      Resistor("R3", 100.0, connection_2, connection_3)));
  circuit2.add_component(std::make_unique<Resistor>(
      Resistor("R4", 300.0, connection_4, connection_2)));
  circuit2.add_component(std::make_unique<Resistor>(
      Resistor("R5", 250.0, connection_4, connection_3)));
  circuit2.simulate(iterations, lines, time_step);
}

void simulate_circuit3(const unsigned int iterations, const unsigned int lines,
                       const double time_step, const double battery_voltage) {
  Network circuit3{};
  Connection connection_1{0};
  Connection connection_2{0};
  Connection connection_3{0};
  Connection connection_4{0};
  circuit3.add_component(std::make_unique<Battery>(
      Battery("Bat", battery_voltage, connection_4, connection_1)));
  circuit3.add_component(std::make_unique<Resistor>(
      Resistor("R1", 150.0, connection_2, connection_1)));
  circuit3.add_component(std::make_unique<Resistor>(
      Resistor("R2", 50.0, connection_3, connection_1)));
  circuit3.add_component(std::make_unique<Capacitor>(
      Capacitor("C3", 1.0, connection_2, connection_3)));
  circuit3.add_component(std::make_unique<Resistor>(
      Resistor("R4", 300.0, connection_4, connection_2)));
  circuit3.add_component(std::make_unique<Capacitor>(
      Capacitor("C5", 0.75, connection_4, connection_3)));
  circuit3.simulate(iterations, lines, time_step);
}
