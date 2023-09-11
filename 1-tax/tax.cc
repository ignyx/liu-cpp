/*
  File: tax.cc
  Authors: Geoffroy Renaut & Paul Alnet
  Created: 30/08/2023
  Course : TDDE18-2023-1
  Description: Tax
    Calculates prices and tax from user input
*/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  float maxValue;
  float minValue;
  float stride;
  float price;
  float tax;
  float priceWithTax;
  bool validValues{false};
  float taxPercentage;
  int i{0};

  cout << "INPUT PART\n"
       << "==========" << endl;

  // Ask for the min and max values until the user provides a correct input
  do {
    cout << " Enter first price : " << endl;
    cin >> minValue;
    cin.clear();
    cin.ignore(100000, '\n');
    cout << " Enter last price : " << endl;
    cin >> maxValue;
    cin.clear();
    cin.ignore(100000, '\n');
    if (maxValue < 0 or minValue < 0) {
      cout << "Please enter non-negative values" << endl;
    } else if (minValue > maxValue) {
      cout << "Please enter a minimum value lower than the max value" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // Ask for the stride until the user provides a correct input
  do {
    validValues = false;
    cout << " Enter stride : " << endl;
    cin >> stride;
    cin.clear();
    cin.ignore(100000, '\n');
    if (stride * 100 < 1) {
      cout << "Please enter a stride greater or equal to 0.01" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // Ask for the tax rate until the user provides a correct input
  do {
    validValues = false;
    cout << "Select tax percentage : " << endl;
    cin >> taxPercentage;
    cin.clear();
    cin.ignore(100000, '\n');
    if (taxPercentage <= 0 or taxPercentage >= 100) {
      cout << "Please select values between 0 and 100" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // display the new mode
  cout << "\n"
       << "TAX TABLE\n"
       << "=========\n"
       << setfill(' ') << right << setw(12) << "PRICE" << setw(12) << "TAX"
       << setw(20) << "PRICE WITH TAX\n"
       << setfill('-') << setw(44) << " " << endl;

  // calculate the new price until it achieve maxValue - stride
  // could be replaced by a simple while
  price = minValue;
  cout << fixed << setprecision(2) << setfill(' ');
  do {
    price = minValue + i * stride;
    tax = (taxPercentage * price) / 100;
    priceWithTax = tax + price;
    i++;
    cout << setw(12) << price << setw(12) << tax << setw(12) << priceWithTax
         << "\n";
  } while (price < (maxValue - stride));
  cout << flush;

  return 0;
}
