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
  bool validValues = false;
  float taxPercentage;
  int i = 0;

  cout << setfill('-') << left << setw(50) << "INPUT PART" << endl;
  cout << " " << endl;

  // Ask for the min and max values until the user gives a correct input
  do {
    cout << " Max and Min values : " << endl;
    cin >> maxValue;
    cin.ignore(100000, ' ');
    cin >> minValue;
    cin.ignore(100000, '\n');
    if (maxValue < 0 or minValue < 0) {
      cout << "Please select positive values" << endl;
    } else if (minValue > maxValue) {
      cout << "Please select a minimum value lower than a max value" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // Ask for the stride until the user give a correct input
  do {
    validValues = false;
    cout << " Enter stride : " << endl;
    cin >> stride;
    cin.ignore(100000, '\n');
    if (stride <= 0.01) {
      cout << "Please select values to 0.01" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // Ask for the tax rate until the user give a correct input
  do {
    validValues = false;
    cout << "Select tax percentage : " << endl;
    cin >> taxPercentage;
    cin.ignore(100000, '\n');
    if (taxPercentage <= 0 or taxPercentage >= 100) {
      cout << "Please select values between 0 and 100" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // display the new mode
  cout << " " << endl;
  cout << setfill('-') << left << setw(50) << "TAX TABLE" << endl;

  cout << " " << endl;
  cout << left << setw(15) << "PRICE " << setw(15) << "TAX " << setw(15)
       << "PRICE WITH TAX" << endl;

  // calculate the new price until it achieve maxValue - stride
  // could be replaced by a simple while
  price = minValue;
  do {
    price = minValue + i * stride;
    tax = (taxPercentage * price) / 100;
    priceWithTax = tax + price;
    i++;
    cout << setfill(' ') << left << setw(5) << price << setw(10) << " "
         << setw(5) << tax << setw(10) << " " << setw(5) << priceWithTax
         << endl;
  } while (price < (maxValue - stride));

  return 0;
}
