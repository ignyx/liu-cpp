#include <initializer_list>
#include <iostream> 
#include <string> 
#include<iomanip>

using namespace std;

struct element
{
     double value;
     element* next;
     element(int value) : value(value), next(nullptr) {}
};

class list {
    public:
    list() : first(nullptr) {}
    list(std::initializer_list<int> list);
     list(const list& other);
    ~list();
    list& operator=(list const& other);
    void insert(double value);
    double find_value_with_rank(int rank);
    int find_rank_with_value(double value);
    void delete_element_with_rank(int rank);
    void delete_element_with_value(double value);
    void display();

    private : 
    element* first;
    int length;

};



//construcor, allow multiple values
list::list(std::initializer_list<int> list){
    for (int i : list) {
        insert(i);
    }
}

//destructor
list::~list(){
    element* current = first;
    while (current != nullptr) {
        element* temp = current;
        current = current->next;
        delete temp;
    }
}

//insert the given value at the right place in the list
void list::insert(double value){
    element* new_element = new element(value);
    if (first == nullptr) {
        first = new_element;
        return;
    }
    element* current_element = first;
    while (current_element->next != nullptr or current_element->value < value) {
        current_element = current_element->next;
    }
    new_element->next = current_element->next;
    current_element->next = new_element;
}

//copy constructor
list::list(const list& other){
    if (other.first != nullptr) {
        element* current_element = other.first;
        while (current_element != nullptr) {
            insert(current_element->value);
            current_element = current_element->next;
        }
    }
}

//return the value stocked at rank "target_rank", if not find, return 0
double list::find_value_with_rank(int target_rank){
    double value = 0;
    if (first == nullptr) {
        return 0;
    }
    int current_rank (0);

    element* current_element = first;
    while (current_element->next != nullptr and current_rank+1!= target_rank) {
        current_element = current_element->next;
        current_rank++;
    }
    if (current_element->next != nullptr) {
        value = current_element->next->value;
    }
    return value;
}

//return the rank of the first apparence of a value, -1 if not found, begin at 0
int list::find_rank_with_value(double value){
    int rank (-1);
    if (first == nullptr) {
        return rank;
    }

    if (first->value == value) {
        return 0;
    }

    element* current_element = first;
    while (current_element->next != nullptr and current_element->next->value != value) {
        current_element = current_element->next;
    }
    if (current_element->next != nullptr) {
        element* temp = current_element->next;
        current_element->next = current_element->next->next;
        delete temp;
    }
    return rank;
}

//delete the element at rank "target_rank", do nothing if rank bigger than the list size, may have return a boolean but flemme
void list::delete_element_with_rank(int target_rank){
    if (first == nullptr) {
        return;
    }
    int current_rank (0);

    element* current_element = first;
    while (current_element->next != nullptr and current_rank+1!= target_rank) {
        current_element = current_element->next;
        current_rank++;
    }
    if (current_element->next != nullptr) {
        element* temp = current_element->next;
        current_element->next = current_element->next->next;
        delete temp;
    }
}

//do the same thing than the previous but with the value instead of the rank
void list::delete_element_with_value(double value){
    if (first == nullptr) {
        return;
    }

    if (first->value == value) {
        element* temp = first;
        first = first->next;
        delete temp;
        return;
    }

    element* current_element = first;
    while (current_element->next != nullptr and current_element->next->value != value) {
        current_element = current_element->next;
    }
    if (current_element->next != nullptr) {
        element* temp = current_element->next;
        current_element->next = current_element->next->next;
        delete temp;
    }
}

//well it display the list
void list::display(){
     element* current = first;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
}

int main(){
    return 0;
}
