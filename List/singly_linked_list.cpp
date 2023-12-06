using namespace std;
#include "singly_linked_list.hpp"
#include <iostream>

/**
 * Destructor for the custom array
 */
template <typename T>
singly_linked_list<T>::~singly_linked_list()
{
    // Free the memory once the object is out of scope
    singly_list_node<T> *free_pointer = head;
    singly_list_node<T> *traverse_pointer;
    while (free_pointer != nullptr)
    {
        traverse_pointer = free_pointer->get_next();
        delete free_pointer;
        free_pointer = traverse_pointer;
    }
}

/**
 * Constructor for an empty singly linked list
 */
template <typename T>
singly_linked_list<T>::singly_linked_list() {}

/**
 * Append an item to the end of the list
 * @param item The item to be added to the end of the list
 */
template <typename T>
bool singly_linked_list<T>::append(T item)
{
    // Initialise a node
    singly_list_node<T> *temp = new singly_list_node<T>(item);

    // Check if the list is empty
    if (this->head == nullptr)
    {
        this->head = temp;
        return true;
    }

    // Traverse to the end of the list and connect the new node
    singly_list_node<T> *traverse_pointer = head;
    while (traverse_pointer->get_next() != nullptr)
    {
        traverse_pointer = traverse_pointer->get_next();
    }

    // Once at the end of the list add the item
    traverse_pointer->set_next(temp);
    return true;
}

/**
 * Remove an item from the list
 * @param item The item to be removed from the list
 */
template <typename T>
bool singly_linked_list<T>::remove(T item)
{

    singly_list_node<T> *travese_pointer = head;

    // Check if the list is empty
    if (travese_pointer == nullptr)
    {
        throw std::out_of_range("The list is empty");
    }

    // If the first item is the item to be deleted move the head to the second item
    if (travese_pointer->get_data() == item)
    {
        head = travese_pointer->get_next();
        delete travese_pointer;
        return true;
    }

    while (travese_pointer->get_next() != nullptr)
    {
        if (travese_pointer->get_next()->get_data() == item)
        {
            // remove the item
            singly_list_node<T> *delete_node = travese_pointer->get_next();
            travese_pointer->set_next(travese_pointer->get_next()->get_next());
            delete delete_node;
            return true;
        }
        travese_pointer = travese_pointer->get_next();
    }

    throw std::out_of_range("The list does not contain the specified value");
}

/**
 * Traverse the list and visualise all of the elements in it
 */
template <typename T>
void singly_linked_list<T>::visualise()
{

    if (head == nullptr)
    {
        throw std::out_of_range("The list is empty");
    }

    singly_list_node<T> *traverse_pointer = head;

    while (traverse_pointer != nullptr)
    {
        traverse_pointer->visualise();
        traverse_pointer = traverse_pointer->get_next();
    }

    cout << endl;
}

/**
 * Traverse the list and check if a node with the given element exist within the list
 * @param item The item to be searched within the list
 */
template <typename T>
bool singly_linked_list<T>::find(T item)
{
    singly_list_node<T> *traverse_pointer = head;

    while (traverse_pointer != nullptr)
    {
        if (traverse_pointer->get_data() == item)
        {
            return true;
        }
        traverse_pointer = traverse_pointer->get_next();
    }

    return false;
}