using namespace std;
#include "array_list.hpp"
#include "math.h"
#include <iostream>

/**
 * Destructor for the custom array
 */
template <typename T>
ArrayList<T>::~ArrayList()
{
    free(data);
}

/**
 * Constructor for an array list without any specified size
 */
template <typename T>
ArrayList<T>::ArrayList() : size(0)
{

    capacity = 10 * scale_factor;

    // Initialise an array with the size given of the given data type
    data = static_cast<T *>(calloc(capacity, sizeof(T)));

    // If allocation did not complete as we wanted
    if (!data)
    {
        cout << "Error allocating memory for array" << endl;
        free(data);
        exit(1);
    }
}

/**
 * Constructor for an array of given size
 */
template <typename T>
ArrayList<T>::ArrayList(int size) : size(size)
{

    capacity = size * scale_factor;

    // Initialise an array with the size given of the given data type
    data = static_cast<T *>(calloc(capacity, sizeof(T)));

    // If allocation did not complete as we wanted
    if (!data)
    {
        cout << "Error allocating memory for array" << endl;
        free(data);
        exit(1);
    }
}

/**
 * Constructor for an array of given size and an existing array of items
 */
template <typename T>
ArrayList<T>::ArrayList(T *items, int size) : size(size)
{
    capacity = scale_factor * size;

    // Allocate new memory to avoid potential dangling pointer issues
    data = static_cast<T *>(calloc(capacity, sizeof(T)));

    // If allocation did not complete as we wanted
    if (!data)
    {
        cout << "Error allocating memory for array" << endl;
        free(data);
        exit(1);
    }

    // Copy the content from the passed array to the new memory location
    for (int i = 0; i < size; i++)
    {
        data[i] = items[i];
    }
}

/**
 * Print out the contents of the array in string form
 */
template <typename T>
void ArrayList<T>::visualise()
{
    // Check if the array is not empty
    if (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }
    else
    {
        cout << "Empty array" << endl;
    }
}

/**
 * Returns the value at a particular position of the array
 */
template <typename T>
T ArrayList<T>::index(int index)
{
    // Check if the index is valid (higher than 0 and less than the size of the array)
    if (index < size && index >= 0)
    {
        return data[index];
    }
}

/**
 * Removes the item at the index of the array list
 */
template <typename T>
bool ArrayList<T>::remove_at(int index)
{
    // Check if the index is valid (higher than 0 and less than the size of the array)
    if (index < size && index >= 0)
    {
        // Move every item after the index one place to the left (overwriting the value at the index)
        move_content(true, index);
        return true;
    }
    else
    {
        throw std::out_of_range("Index out of range");
    }
}

/**
 * Removes a given item from the array list
 * Removes the first occurance of the item
 * @param item Value to remove from the list (Note this parameter is a value not a reference)
 */
template <typename T>
bool ArrayList<T>::remove(T item)
{

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == item)
        {
            found = true;
            move_content(true, i);
            size--;
            return true;
        }
    }

    if (!found)
    {
        cout << "The specified item was not found in the array list";
        return false;
    }
}

/**
 * Index the array using []
 * This is for reference arrays (values inside can change using this)
 */
template <typename T>
T &ArrayList<T>::operator[](int index)
{
    // Check if the index is valid (higher than 0 and less than the size of the array)
    if (index < size && index >= 0)
    {
        return data[index];
    }
    throw std::out_of_range("Index out of range");
}

/**
 * Index the array using []
 * Returns a copy (non mutable)
 */
template <typename T>
T ArrayList<T>::operator[](int index) const
{
    // Check if the index is valid (high er than 0 and less than the size of the array)
    if (index < size && index >= 0)
    {
        return data[index];
    }
    throw std::out_of_range("Index out of range");
}

/**
 * Function for appending an item to a given index
 */
template <typename T>
bool ArrayList<T>::append(T item, int index)
{
    if (index < size && index >= 0)
    {
        // Move the existing item at the index and everything after it one position to the right
        move_content(false, index);
        data[index] = item;
        return true;
    }

    return false;
};

/**
 * Function for appending an item to the end of the array list
 */
template <typename T>
bool ArrayList<T>::append(T item)
{
    // Check if there is enough capacity to add a new item
    if (size + 1 > capacity)
    {
        extend_capacity();
    }

    data[size] = item;
    size++;

    return false;
};

/**
 * Returns the size of the array
 */
template <typename T>
int ArrayList<T>::length()
{
    return size;
}

/**
 * Returns the current capacity of the array list
 */
template <typename T>
int ArrayList<T>::get_capacity()
{
    return capacity;
}

/**
 * Helper function used for moving elements of the array either left (after removing) or right (after adding)
 * @param direction is either true or false (true for moving left, false for right)
 * @param index the index of the item to start moving from
 */
template <typename T>
bool ArrayList<T>::move_content(bool direction, int index)
{
    if (direction)
    {
        // Move all elements after the index to the left
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;
    }
    else
    {
        // Check if we have enough capacity for moving the elements
        if (capacity < size + 1)
        {
            // Allocate more memory
            // This function does error handling and if memory allocation fails, it will exit
            extend_capacity();
        }

        // Move all elements after the index to the right
        // Iterate backwards from the right (so that we don't need a temporary vairables to copy elements to)
        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }

        size++;
    }
    return true;
}

/**
 * Helper function for extending the capacity of the array list
 */
template <typename T>
bool ArrayList<T>::extend_capacity()
{
    int new_capacity = size * scale_factor;
    T *new_array = static_cast<T *>(realloc(data, new_capacity * sizeof(T)));

    if (!new_array)
    {
        cout << "Error allocating memory for array" << endl;
        free(data);
        exit(1);
    }

    data = new_array;
    capacity = new_capacity;
    return true;
}