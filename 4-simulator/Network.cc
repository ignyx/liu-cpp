#include "Network.h"
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

using namespace std;


Component::Component(std::string const &name, Connection &terminal_a,
            Connection &terminal_b)
      : name{name}, terminal_a{terminal_a}, terminal_b{terminal_b} {};

double Component::get_voltage() const {
  return terminal_b.potential - terminal_a.potential;
}

void Component::run_step(const double) {}

std::string const &Component::get_name() const { return name; }

Network::Network() : components{} {};

void Network::add_component(unique_ptr<Component> new_component) {
  components.push_back(std::move(new_component));
}

std::vector<std::unique_ptr<Component>> &Network::get_components() {
  return components;
}

void Network::simulate(unsigned int iterations, unsigned int lines,
                       double time_step) {
  cout << setfill(' ') << fixed << setprecision(2);

  for (const unique_ptr<Component> &component : components) {
    cout << right << setw(16) << component->get_name();
  }
  cout << endl;
  for (unsigned int i{0}; i < components.size(); i++) {
    cout << right << setw(8) << "Volt" << setw(8) << "Curr";
  }
  cout << endl;

  const unsigned int iterations_between_lines{iterations / lines};

  for (unsigned int i{0}; i < iterations; i++) {
    const bool lign_shown{i % iterations_between_lines ==
                          iterations_between_lines - 1};

    for (const unique_ptr<Component> &component : components) {
      component->run_step(time_step);

      if (lign_shown) {
        cout << right << setw(8) << component->get_voltage() << setw(8)
             << component->get_current();
      }
    }
    if (lign_shown)
      cout << endl;
  }
}

Resistor::Resistor(std::string const &name, double resistance, Connection &terminal_a,
           Connection &terminal_b)
      : Component{name, terminal_a, terminal_b}, resistance{resistance} {};

double Resistor::get_current() const { return get_voltage() / resistance; }

void Resistor::run_step(const double time) {
  double charge_difference((get_voltage() / resistance) * time);
  terminal_a.potential += charge_difference;
  terminal_b.potential -= charge_difference;
}

Capacitor::Capacitor(std::string const &name, double capacitance, Connection &terminal_a,
            Connection &terminal_b)
      : Component{name, terminal_a, terminal_b}, capacitance{capacitance},
        stored_charge{0} {};

double Capacitor::get_current() const {
  return capacitance * (get_voltage() - stored_charge);
}

void Capacitor::run_step(const double time) {
  double charge_difference{capacitance * (get_voltage() - stored_charge) *
                           time};

  stored_charge += charge_difference;
  terminal_a.potential += charge_difference;
  terminal_b.potential -= charge_difference;
}

Battery::Battery(std::string const &name, double voltage, Connection &terminal_a,
          Connection &terminal_b)
      : Component{name, terminal_a, terminal_b}, voltage{voltage} {};

double Battery::get_current() const { return 0; }

void Battery::run_step(const double) {
  terminal_a.potential = 0;
  terminal_b.potential = voltage;
}
