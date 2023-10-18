#ifdef LIST_H
#define LIST_H

struct element
{
     double value;
     element* next;
     element(int value) : value(value), next(nullptr) {}
};

class list {
    public:
    list() : first(nullptr) {};
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

#endif