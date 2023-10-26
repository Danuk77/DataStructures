using namespace std;
#include "custom_array.hpp"
#include <iostream>

/**
 * Destructor for the custom array
 */
template <typename T>
CustomArray<T>::~CustomArray()
{
    free(data);
}

/**
 * Constructor for an array of given size
 */
template <typename T>
CustomArray<T>::CustomArray(int size) : size(size)
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
CustomArray<T>::CustomArray(T *items, int size) : size(size)
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
void CustomArray<T>::visualise()
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
T CustomArray<T>::index(int index)
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
 * This is for reference arrays (values inside can change using this)
 */
template <typename T>
T &CustomArray<T>::operator[](int index)
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
T CustomArray<T>::operator[](int index) const
{
    // Check if the index is valid (high er than 0 and less than the size of the array)
    if (index < size && index >= 0)
    {
        return data[index];
    }
    throw std::out_of_range("Index out of range");
}

/**
 * Function for inserting an element at a particular index
 * Also used for changing an existing item at a particular index
 */
template <typename T>
bool CustomArray<T>::insert(T item, int index)
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
int CustomArray<T>::length()
{
    return size;
}