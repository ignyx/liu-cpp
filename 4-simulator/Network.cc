#include <initializer_list>
#include <iostream> 
#include <string> 
#include <iomanip>
#include "Network.h"

using namespace std;
 
 
 double const Component::get_voltage(){
    return *terminal_b.potential-*terminal_a.potential;
 }

 std::string const Component::&get_name(){
    return &name;
 }


void add_component(Component &component){
    push_back(component);
};

double const Component::get_current(){
    return 0;
}

double const Resistor::get_current(){
    return get_voltage()/resistance;
}

double const Capacitor::get_current(){
    return capacitance*(get_voltage()-stored_charge);
}

void Capacitor::run_step(const double time){
    double charge_difference(capacitance*get_voltage()*time);
    stored_charge = stored_charge + charge_difference;
    *terminal_a.potential=*terminal_a.potential+charge_difference;
    *terminal_b.potential=*terminal_b.potential-charge_difference;
}

void Capacitor::run_step(const double time){
    double charge_difference((get_voltage()/resistance)*time);
    *terminal_a.potential=*terminal_a.potential+charge_difference;
    *terminal_b.potential=*terminal_b.potential-charge_difference;
}