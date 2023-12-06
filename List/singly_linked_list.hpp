#pragma once
#include "singly_list_node.hpp"
template <typename T>

class singly_linked_list
{
private:
    singly_list_node<T> *head = nullptr;

public:
    ~singly_linked_list();
    singly_linked_list();
    bool append(T item);
    bool remove(T item);
    void visualise();
    bool find(T item);
    // bool update(T item);
};

// Include the implementation (this is the norm for implementing template classes)
#include "singly_linked_list.cpp"