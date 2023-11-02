#include "Network.h"
#include <string>

using namespace std;

double Component::get_voltage() {
  return terminal_b.potential - terminal_a.potential;
}

void Component::run_step(const double) {}

std::string const &Component::get_name() { return name; }

void Network::add_component(Component &component) {
  components.push_back(component);
}

double Component::get_current() { return 0; }

double Resistor::get_current() { return get_voltage() / resistance; }

double Capacitor::get_current() {
  return capacitance * (get_voltage() - stored_charge);
}

void Capacitor::run_step(const double time) {
  double charge_difference(capacitance * get_voltage() * time);
  stored_charge = stored_charge + charge_difference;
  terminal_a.potential = terminal_a.potential + charge_difference;
  terminal_b.potential = terminal_b.potential - charge_difference;
}

void Resistor::run_step(const double time) {
  double charge_difference((get_voltage() / resistance) * time);
  terminal_a.potential = terminal_a.potential + charge_difference;
  terminal_b.potential = terminal_b.potential - charge_difference;
}
