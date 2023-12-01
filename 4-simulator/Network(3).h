
#ifndef NETWORK_H
#define NETWORK_H

#include <memory>
#include <string>
#include <vector>

struct Connection {
  double potential{0};
};

class Component {
public:
  Component(std::string const &name, Connection &terminal_a,
            Connection &terminal_b);
  virtual ~Component() = default; // virtual destructor

  double get_voltage() const;
  std::string const &get_name() const;

  //virtual functions
  virtual double get_current() const = 0;
  virtual void run_step(const double time);
  

private:
  std::string name;

protected:
  Connection &terminal_a;
  Connection &terminal_b;
};

class Network {
public:
  Network();
  void simulate(unsigned int interations, unsigned int lines, 
          double time_step);
  void add_component(std::unique_ptr<Component> component);

private:
  std::vector<std::unique_ptr<Component>> components;
};

class Battery : public Component {
public:
  Battery(std::string const &name, double voltage, 
          Connection &terminal_a, Connection &terminal_b);
  double get_current() const override;
  void run_step(const double time) override;

private:
  const double voltage;
};

class Resistor : public Component {
public:
  Resistor(std::string const &name, double resistance, 
            Connection &terminal_a, Connection &terminal_b);
  double get_current() const override;
  void run_step(const double time) override;

private:
  const double resistance;
};

class Capacitor : public Component {
public:
  Capacitor(std::string const &name, double capacitance, 
            Connection &terminal_a, Connection &terminal_b);
  double get_current() const override;
  void run_step(const double time) override;

private:
  const double capacitance;
  double stored_charge;
};

#endif // NETWORK_H
