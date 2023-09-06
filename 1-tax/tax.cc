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

  cout << setfill('-') << left << setw(50) << "INPUT PART" << endl;
  cout << " " << endl;

  // Ask for the min and max values until the user provides a correct input
  do {
    cout << " Enter first price : " << endl;
    cin >> minValue;
    cin.ignore(100000, '\n');
    cout << " Enter last price : " << endl;
    cin >> maxValue;
    cin.ignore(100000, '\n');
    if (maxValue < 0 or minValue < 0) {
      cout << "Please select positive values" << endl;
    } else if (minValue > maxValue) {
      cout << "Please select a minimum value lower than a max value" << endl;
    } else {
      validValues = true;
    }
  } while (validValues == false);

  // Ask for the stride until the user provides a correct input
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

  // Ask for the tax rate until the user provides a correct input
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
  cout << setfill(' ') << right << setw(12) << "PRICE" << setw(12) << "TAX"
       << setw(20) << "PRICE WITH TAX" << endl;

  // calculate the new price until it achieve maxValue - stride
  // could be replaced by a simple while
  price = minValue;
  cout << fixed << setprecision(2);
  do {
    price = minValue + i * stride;
    tax = (taxPercentage * price) / 100;
    priceWithTax = tax + price;
    i++;
    cout << setfill(' ') << right << setw(12) << price << setw(12) << tax
         << setw(12) << priceWithTax << endl;
  } while (price < (maxValue - stride));

  return 0;
}
