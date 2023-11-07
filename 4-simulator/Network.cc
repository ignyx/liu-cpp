#include "Network.h"
#include <string>

using namespace std;

double Component::get_voltage() {
  return terminal_b.potential - terminal_a.potential;
}

double Component::get_current() { return 0; }

void Component::run_step(const double) {}

std::string const &Component::get_name() { return name; }

void Network::add_component(Component &component) {
  components.push_back(component);
}

std::vector<Component> &Network::get_components() { return components; }

void Network::simulate(unsigned int iterations, unsigned int lines,
                       double time_step) {
  for (unsigned int i = 0; i < iterations; i++) {
    for (int j = 0; j < components.size(); j++) {
      components[i].run_step(time_step);
    }
  }
}

double Resistor::get_current() { return get_voltage() / resistance; }

void Resistor::run_step(const double time) {
  double charge_difference((get_voltage() / resistance) * time);
  terminal_a.potential = terminal_a.potential + charge_difference;
  terminal_b.potential = terminal_b.potential - charge_difference;
}

double Capacitor::get_current() {
  return capacitance * (get_voltage() - stored_charge);
}

void Capacitor::run_step(const double time) {
  double charge_difference(capacitance * get_voltage() * time);
  stored_charge = stored_charge + charge_difference;
  terminal_a.potential = terminal_a.potential + charge_difference;
  terminal_b.potential = terminal_b.potential - charge_difference;
}

void Battery::run_step(const double time) {
  terminal_a.potential = voltage;
  terminal_b.potential = 0;
}
