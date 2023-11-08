#include "list.h"
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


struct Element {
  int value;
  Element *next;
  Element(int value) : value(value), next(nullptr) {}
};

List::List() : first(nullptr) {}

// construcor, allow multiple values
List::List(std::initializer_list<int> list) : first(nullptr) {
  for (int value : list) {
    insert(value);
  }
}

// destructor
List::~List() {
  Element *current{first};
  while (current != nullptr) {
    Element *temp{current};
    current = current->next;
    delete temp;
  }
}

// insert the given value at the right place in the list
void List::insert(int value) {
  Element *new_element{new Element(value)};
  if (first == nullptr or value < first->value) {
    new_element->next = first;
    first = new_element;
    return;
  }

  Element *current_element{first};
  while (current_element->next != nullptr and
         current_element->next->value < value) {
    current_element = current_element->next;
  }
  new_element->next = current_element->next;
  current_element->next = new_element;
}

// helper function
void deep_copy(Element *current_source, Element *current_copy) {
  while (current_source->next != nullptr) {
    current_copy->next = new Element(current_source->next->value);

    current_source = current_source->next;
    current_copy = current_copy->next;
  }
}

// copy constructor
List::List(const List &other) : first(nullptr) {
  if (other.first != nullptr) {
    Element *current_source{other.first};
    Element *current_copy{new Element(other.first->value)};

    deep_copy(current_source, current_copy);
    first = current_copy;
  }
}

// move constructor
List::List(List &&other) : first(other.first) { other.first = nullptr; }

// return the value stocked at rank "target_rank", if not find, return 0
int List::find_value_with_rank(int target_rank) const {
  if (target_rank < 0)
    return 0; // ideally would return an error

  int current_rank{0};
  Element *current_element{first};

  while (current_element != nullptr and current_rank < target_rank) {
    current_rank++;
    current_element = current_element->next;
  }
  if (current_element != nullptr)
    return current_element->value;
  return 0;
}

// return the rank of the first apparence of a value, -1 if not found, begin at
// 0
int List::find_rank_with_value(int value) const {
  if (first == nullptr) {
    return -1;
  } else if (first->value == value) {
    return 0;
  }
  int rank{1};

  Element *current_element{first};
  while (current_element->next != nullptr and
         current_element->next->value != value) {
    rank++;
    current_element = current_element->next;
  }
  if (current_element->next == nullptr) {
    return -1;
  }
  return rank;
}

void delete_next_element(Element *element) {
  Element *temp{element->next};
  element->next = element->next->next;
  delete temp;
}

// delete the Element at rank "target_rank", do nothing if rank bigger than the
// list size
void List::delete_element_with_rank(int target_rank) {
  if (first == nullptr or target_rank < 0)
    return;
  else if (target_rank == 0) {
    Element *temp{first};
    first = first->next;
    delete temp;
    return;
  }

  Element *current_element{first};
  int next_rank{1};

  while (current_element->next != nullptr and next_rank < target_rank) {
    current_element = current_element->next;
    next_rank++;
  }

  if (current_element->next != nullptr and next_rank == target_rank) {
    delete_next_element(current_element);
  }
}

// do the same thing than the previous but with the value instead of the rank
void List::delete_element_with_value(int value) {
  if (first == nullptr) {
    return;
  } else if (first->value == value) {
    Element *temp{first};
    first = first->next;
    delete temp;
    return;
  }

  Element *current_element{first};
  while (current_element->next != nullptr and
         current_element->next->value != value) {
    current_element = current_element->next;
  }
  if (current_element->next != nullptr) {
    delete_next_element(current_element);
  }
}

string element_to_string(Element *element) {
  if (element->next == nullptr)
    return to_string(element->value);
  else
    return to_string(element->value) + " " + element_to_string(element->next);
}

string List::to_string() const {
  if (first == nullptr)
    return "";
  else
    return element_to_string(first);
}

// display a linked list of elements
void List::print() const { cout << to_string(); }

int List::size() const {
  int count{0};
  Element *current{first};
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

// helper function
void delete_list(Element *element) {
  while (element != nullptr) {
    Element *temp{element};
    element = element->next;
    delete temp;
  }
}

bool List::is_empty() const { return first == nullptr; }

// copy assignment operator
List &List::operator=(List const &other) {
  // Prevent self-assignment
  if (first == other.first)
    return *this;

  delete_list(first);
  first = nullptr;

  if (other.first != nullptr) {
    first = new Element(other.first->value);
    deep_copy(other.first, first);
  }

  return *this;
}

// move assignment operator
List &List::operator=(List &&other) {
  // Prevent self-assignment
  if (first == other.first)
    return *this;

  delete_list(first);
  first = other.first;
  other.first = nullptr;

  return *this;
}
