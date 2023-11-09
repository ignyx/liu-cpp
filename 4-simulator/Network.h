#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <vector>

struct Connection {
  double potential = 0;
};

class Component {
public:
  Component(std::string const &name, Connection &terminal_a,
            Connection &terminal_b)
      : name{name}, terminal_a{terminal_a}, terminal_b{terminal_b} {};
  virtual ~Component() = default; // virtual destructor
  double get_voltage() const;
  virtual double get_current() const;
  virtual void run_step(const double time);
  std::string const &get_name() const;

private:
  std::string name;

protected:
  Connection &terminal_a;
  Connection &terminal_b;
};

class Network {
public:
  Network() : components{} {};
  void simulate(unsigned int interations, unsigned int lines, double time_step);
  std::vector<Component *> &get_components();
  void add_component(Component *component);
  // deallocate ?
private:
  std::vector<Component *> components;
  // connections ?
};

class Battery : public Component {
public:
  Battery(std::string const &name, double voltage, Connection &terminal_a,
          Connection &terminal_b)
      : Component{name, terminal_a, terminal_b}, voltage{voltage} {};
  void run_step(const double time) override;

private:
  const double voltage;
};

class Resistor : public Component {
public:
  Resistor(std::string const &name, double resistance, Connection &terminal_a,
           Connection &terminal_b)
      : Component{name, terminal_a, terminal_b}, resistance{resistance} {};
  double get_current() const override;
  void run_step(const double time) override;

private:
  const double resistance;
};

class Capacitor : public Component {
public:
  Capacitor(std::string const &name, double capacitance, Connection &terminal_a,
            Connection &terminal_b)
      : Component{name, terminal_a, terminal_b}, capacitance{capacitance},
        stored_charge{0} {};
  double get_current() const override;
  void run_step(const double time) override;

private:
  const double capacitance;
  double stored_charge;
};

#endif // NETWORK_H
