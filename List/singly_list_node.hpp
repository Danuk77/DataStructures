#pragma once
/**
 * Class structure for a node of a singly linked list
 */
template <typename T>
class singly_list_node
{
private:
    T data;
    singly_list_node *next = nullptr;

public:
    ~singly_list_node();
    singly_list_node(T item);
    void visualise();
    T get_data();
    void set_data(T item);
    singly_list_node *get_next();
    void set_next(singly_list_node<T> *new_location);
};

#include "singly_list_node.cpp"