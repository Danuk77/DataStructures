using namespace std;
#include "singly_list_node.hpp"
#include <iostream>

/**
 * Destructor for the custom array
 */
template <typename T>
singly_list_node<T>::~singly_list_node()
{
}

/**
 * Constructor for a node in a singly linked list
 * @param initial data item of the node
 */
template <typename T>
singly_list_node<T>::singly_list_node(T item) : data(item) {}

/**
 * Print the data item held by the node
 */
template <typename T>
void singly_list_node<T>::visualise()
{
    cout << data << "--";
}

/**
 * Getter for retrieving the data in the field
 */
template <typename T>
T singly_list_node<T>::get_data()
{
    return data;
}

/**
 * Setter for setting the data in the field
 * @param item The new value to be held by the node
 */
template <typename T>
void singly_list_node<T>::set_data(T item)
{
    data = item;
}

/**
 * Getter for retrieving the next pointer
 */
template <typename T>
singly_list_node<T> *singly_list_node<T>::get_next()
{
    return next;
}

/**
 * Setter for setting the next pointer
 */
template <typename T>
void singly_list_node<T>::set_next(singly_list_node<T> *new_location)
{
    next = new_location;
}
