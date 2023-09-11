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

  cout << "INPUT PART\n"
       << "==========" << endl;

  // Ask for the min value until the user provides a correct input
  do {
    cout << " Enter first price : " << endl;
    cin >> minValue;
    cin.clear();
    cin.ignore(100000, '\n');
    if (minValue < 0) {
      cout << "Please enter a non-negative min value" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // Ask for the max value until the user provides a correct input
  validValues = false;
  do {
    cout << " Enter last price : " << endl;
    cin >> maxValue;
    cin.clear();
    cin.ignore(100000, '\n');
    if (maxValue < 0) {
      cout << "Please enter non-negative max value" << endl;
    } else if (minValue > maxValue) {
      cout << "Please enter a max value greater than the min value" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // Ask for the stride until the user provides a correct input
  validValues = false;
  do {
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
  validValues = false;
  do {
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

  // format table
  cout << fixed << setprecision(2) << setfill(' ');

  // output prices
  for (int i = 0; i <= (maxValue - minValue) / stride; i++) {
    price = minValue + i * stride;
    tax = (taxPercentage * price) / 100;
    priceWithTax = tax + price;
    cout << setw(12) << price << setw(12) << tax << setw(12) << priceWithTax
         << "\n";
  }
  cout << flush;

  return 0;
}
