#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <vector>

class Connection {
public:
  double potential;
};

class Component {
public:
  Component(std::string const &name, Connection &terminal_a,
            Connection &terminal_b);
  double const get_voltage();
  virtual double const get_current();
  virtual void run_tick();
  std::vector<Connection> const &get_terminals();
  std::string const &get_name();

private:
  Connection &terminal_a;
  Connection &terminal_b;
};

class Network {
public:
  void simulate(unsigned int interations, unsigned int lines, double time_step);
  std::vector<Component> const &get_components();
  void add_component(Component component);
  // deallocate ?
};

class Battery : public Component {
public:
  Battery(std::string const &name, double voltage, Connection terminal_a,
          Connection terminal_b);
  double const get_current();
  void run_tick();
};

class Resistor : public Component {
public:
  Resistor(std::string const &name, double resistance, Connection terminal_a,
           Connection terminal_b);
  double const get_current();
  void run_tick();
};

class Capacitor : public Component {
public:
  Capacitor(std::string const &name, double capacitance, Connection terminal_a,
            Connection terminal_b);
  double const get_current();
  void run_tick();
};

#endif // NETWORK_H
