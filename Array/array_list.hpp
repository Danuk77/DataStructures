#pragma once
template <typename T>

class ArrayList
{
private:
    int size;
    T *data;
    int capacity;
    int scale_factor = 2;
    bool move_content(bool direction, int index);
    bool extend_capacity();

public:
    ~ArrayList();
    ArrayList();
    ArrayList(int size);
    ArrayList(T *items, int size);
    bool append(T item, int index);
    bool append(T item);
    bool remove_at(int index);
    bool remove(T item);
    void visualise();
    T index(int index);
    int length();
    int get_capacity();

    // Operator overloading
    T &operator[](int index);
    T operator[](int index) const;
};

// Include the implementation (this is the norm for implementing template classes)
#include "array_list.cpp"