#include "Network.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

double Component::get_voltage() const {
  return terminal_b.potential - terminal_a.potential;
}

double Component::get_current() const { return 0; }

void Component::run_step(const double) {}

std::string const &Component::get_name() const { return name; }

void Network::add_component(Component *new_component) {
  components.push_back(new_component);
}

std::vector<Component *> &Network::get_components() { return components; }

void Network::simulate(unsigned int iterations, unsigned int lines,
                       double time_step) {
  for (int j = 0; j < components.size(); j++) {
    Component *temp = components[j];
    cout << setfill(' ') << left << setw(24) << temp->get_name();
  }
  cout << endl;
  for (unsigned int i = 0; i < iterations; i++) {
    for (Component *j : components) {
      j->run_step(time_step);

      if (i % (iterations / lines) == 0) {
        cout << setfill(' ') << right << setw(12) << j->get_current()
             << setw(12) << j->get_voltage();
      }
    }
    cout << endl;
  }
}

double Resistor::get_current() const { return get_voltage() / resistance; }

void Resistor::run_step(const double time) {
  double charge_difference((get_voltage() / resistance) * time);
  terminal_a.potential = terminal_a.potential + charge_difference;
  terminal_b.potential = terminal_b.potential - charge_difference;
}

double Capacitor::get_current() const {
  return capacitance * (get_voltage() - stored_charge);
}

void Capacitor::run_step(const double time) {
  double charge_difference{capacitance * (get_voltage() - stored_charge) *
                           time};

  stored_charge = stored_charge + charge_difference;
  terminal_a.potential = terminal_a.potential + charge_difference;
  terminal_b.potential = terminal_b.potential - charge_difference;
}

void Battery::run_step(const double) {
  terminal_a.potential = 0;
  terminal_b.potential = voltage;
}
