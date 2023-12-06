using namespace std;
#pragma once

// A node in a doubly linked list
template <typename T>
struct doubly_linked_node
{
    T data;
    doubly_linked_node<T> *prev = nullptr;
    doubly_linked_node<T> *next = nullptr;

    /**
     * Constructor for the node
     * @param item The initial value held by the node
     */
    doubly_linked_node(T item, doubly_linked_node<T> *prev, doubly_linked_node<T> *next) : data(item), prev(prev), next(next){};
};

// A doubly linked list structure
template <typename T>
struct doubly_linked_list
{
    doubly_linked_node<T> *head = nullptr;
    doubly_linked_node<T> *tail = nullptr;

    doubly_linked_list(){};
    doubly_linked_list(T item) { head = new doubly_linked_node<T>(item, nullptr, nullptr); };

    /**
     * Destructor - Traverse the list and free all the memory allocated
     */
    ~doubly_linked_list()
    {
        doubly_linked_node<T> *traverse_pointer = head;
        doubly_linked_node<T> *free_pointer = head;
        while (traverse_pointer != nullptr)
        {
            traverse_pointer = free_pointer->next;
            delete free_pointer;
            free_pointer = traverse_pointer;
        }
    }

    /**
     * Append an item to the end of the list
     * @param item The value to add at the end of the list
     */
    bool append(T item)
    {

        // Check if the list is empty
        if (head == nullptr)
        {
            doubly_linked_node<T> *new_node = new doubly_linked_node<T>(item, nullptr, nullptr);
            head = new_node;
            tail = new_node;
            return true;
        }

        doubly_linked_node<T> *new_node = new doubly_linked_node<T>(item, tail, nullptr);
        tail->next = new_node;
        return true;
    }

    /**
     * Remove an element from the list
     * @param item The value to remove from the list
     */
    bool remove(T item)
    {
        doubly_linked_node<T> *traverse_pointer = head;
        while (head != nullptr)
        {
            if (traverse_pointer->data == item)
            {
                // Check if its the first item in the list
                if (traverse_pointer->prev != nullptr)
                {
                    traverse_pointer->prev->next = traverse_pointer->next;
                }
                else
                {
                    head = traverse_pointer->next;
                }

                // Check if its the last item in the list
                if (traverse_pointer->next != nullptr)
                {
                    traverse_pointer->next->prev = traverse_pointer->prev;
                }
                else
                {
                    tail = traverse_pointer->prev;
                }

                delete traverse_pointer;
                return true;
            }

            traverse_pointer = traverse_pointer->next;
        }

        throw std::out_of_range("The value was not found in the list");
    }

    /**
     * Find if a value exist within the list
     * @param item The value to find
     */
    bool find(T item)
    {
        doubly_linked_node<T> *traverse_pointer = head;

        while (traverse_pointer != nullptr)
        {
            if (traverse_pointer->data == item)
            {
                return true;
            }

            traverse_pointer = traverse_pointer->next;
        }

        return false;
    }

    /**
     * Print out the list
     */
    void visualise()
    {
        doubly_linked_node<T> *traverse_pointer = head;

        while (traverse_pointer != nullptr)
        {
            cout << traverse_pointer->data << " ";
            traverse_pointer = traverse_pointer->next;
        }

        cout << endl;
    }
};