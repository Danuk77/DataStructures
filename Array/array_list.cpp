using namespace std;
#include "array_list.hpp"
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
 * Constructor for an array of given size
 */
template <typename T>
ArrayList<T>::ArrayList(int size) : size(size)
{
    // Initialise an array with the size given of the given data type
    data = static_cast<T *>(calloc(size, sizeof(T)));

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
    // Allocate new memory to avoid potential dangling pointer issues
    data = static_cast<T *>(calloc(size, sizeof(T)));

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
bool ArrayList<T>::remove(int index)
{
    // Check if the index is valid (higher than 0 and less than the size of the array)
    if (index < size && index >= 0)
    {
        return data[index];
    }
}

/**
 * Removes a given item from the array list
 * Removes the first occurance of the item
 */
template <typename T>
bool ArrayList<T>::remove(T item)
{
    // Check if the index is valid (higher than 0 and less than the size of the array)
    if (index < size && index >= 0)
    {
        return data[index];
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
 * Passes a copy (non mutable)
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
 * Function for appending an item to the end of the array list
 */
template <typename T>
bool ArrayList<T>::append(T item, int index)
{
    if (index < size && index >= 0)
    {
        data[index] = item;
        return true;
    }
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