#include "list.h"
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// construcor, allow multiple values
List::List(std::initializer_list<double> list) : first(nullptr) {
  for (double value : list) {
    insert(value);
  }
}

// destructor
List::~List() {
  Element *current = first;
  while (current != nullptr) {
    Element *temp = current;
    current = current->next;
    delete temp;
  }
}

// insert the given value at the right place in the list
void List::insert(double value) {
  Element *new_element = new Element(value);
  if (first == nullptr) {
    first = new_element;
    return;
  } else if (value < first->value) {
    new_element->next = first;
    first = new_element;
    return;
  }

  Element *current_element = first;
  while (current_element->next != nullptr and current_element->value < value) {
    current_element = current_element->next;
  }
  new_element->next = current_element->next;
  current_element->next = new_element;
}

// copy constructor
List::List(const List &other) : first(nullptr) {
  Element *current_element = other.first;
  while (current_element != nullptr) {
    cout << current_element->value;
    insert(current_element->value);
    cout << "ok" << flush;

    current_element = current_element->next;
  }
}

// return the value stocked at rank "target_rank", if not find, return 0
double List::find_value_with_rank(int target_rank) {
  int current_rank{0};
  Element *current_element{first};

  while (current_element != nullptr and current_rank < target_rank) {
    current_rank++;
    current_element = current_element->next;
  }
  if (current_element != nullptr)
    return current_element->value;
  return 0.0;
}

// return the rank of the first apparence of a value, -1 if not found, begin at
// 0
int List::find_rank_with_value(double value) {
  int rank(-1);
  if (first == nullptr) {
    return rank;
  }

  if (first->value == value) {
    return 0;
  }

  Element *current_element = first;
  while (current_element->next != nullptr and
         current_element->next->value != value) {
    current_element = current_element->next;
  }
  if (current_element->next != nullptr) {
    Element *temp = current_element->next;
    current_element->next = current_element->next->next;
    delete temp;
  }
  return rank;
}

// delete the Element at rank "target_rank", do nothing if rank bigger than the
// list size, may have return a boolean but flemme
void List::delete_element_with_rank(int target_rank) {
  if (first == nullptr) {
    return;
  }
  int current_rank(0);

  Element *current_element = first;
  while (current_element->next != nullptr and current_rank + 1 != target_rank) {
    current_element = current_element->next;
    current_rank++;
  }
  if (current_element->next != nullptr) {
    Element *temp = current_element->next;
    current_element->next = current_element->next->next;
    delete temp;
  }
}

// do the same thing than the previous but with the value instead of the rank
void List::delete_element_with_value(double value) {
  if (first == nullptr) {
    return;
  }

  if (first->value == value) {
    Element *temp = first;
    first = first->next;
    delete temp;
    return;
  }

  Element *current_element = first;
  while (current_element->next != nullptr and
         current_element->next->value != value) {
    current_element = current_element->next;
  }
  if (current_element->next != nullptr) {
    Element *temp = current_element->next;
    current_element->next = current_element->next->next;
    delete temp;
  }
}

// recursively display a linked list of elements
void display_list(Element *element) {
  cout << element->value << " ";
  if (element->next != nullptr)
    display_list(element->next);
  else
    cout << endl;
}

// well it display the list
void List::display() {
  Element *current = first;
  if (current != nullptr)
    display_list(current);
}

int List::size() {
  int count{0};
  Element *current{first};
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

bool List::is_empty() { return first == nullptr; }
