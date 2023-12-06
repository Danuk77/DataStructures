#include "binary_tree.hpp"

// Destructor
template <typename T>
tree_node<T>::~tree_node()
{
    if (left != nullptr)
    {
        delete left;
    }

    if (right != nullptr)
    {
        delete right;
    }
}

/**
 * Constructor for a tree leaf
 * @param item The value to be held by the node
 */
template <typename T>
tree_node<T>::tree_node(T item) : data(item)
{
}

/**
 * Constructor for a tree node
 * @param item The value to be held by the node
 * @param left_ptr A pointer to the left sub tree of the node
 * @param right_ptr A pointer to the right subtree of the node
 */
template <typename T>
tree_node<T>::tree_node(T item, tree_node<T> *left_ptr, tree_node<T> *right_ptr) : data(item), left(left_ptr), right(right_ptr)
{
}

/**
 * Update the value held by the node to the value specified
 * @param item The new value to be stored in the node
 */
template <typename T>
void tree_node<T>::update(T item)
{
    data = item;
}

/**
 * Update the left subtree of the node
 * @param left_subtree The new left subtree
 */
template <typename T>
void tree_node<T>::update_left_subtree(tree_node<T> *left_subtree)
{
    left = left_subtree;
}

/**
 * Update the right subtree of the node
 * @param right_subtree The new left subtree
 */
template <typename T>
void tree_node<T>::update_right_subtree(tree_node<T> *right_subtree)
{
    right = right_subtree;
}

/**
 * Insert the given item (recursively travel until the leaves are reached)
 * @param item The item to insert
 */
template <typename T>
bool tree_node<T>::insert(T item)
{
    if (data >= item)
    {
        return insert_at_leaf(left, item);
    }
    else
    {
        return insert_at_leaf(right, item);
    }
}

/**
 * Checks if a given child of a node is a leaf
 * If it is a leaf creates a new node at the leaf
 * Otherwise recursively traverses the inner node
 * @param child The node to check if it is a child
 * @param item The item to be added
 */
template <typename T>
bool tree_node<T>::insert_at_leaf(tree_node<T> *&child, T item)
{
    if (child == nullptr)
    {
        child = new tree_node<T>(item, nullptr, nullptr);
        return true;
    }
    else
    {
        return child->insert(item);
    }
}

/**
 * Recursively check if the given node is present in the binary tree
 * @param item The value to be searched through the binary tree
 * @return Returns the address of the node containing this value
 */
template <typename T>
tree_node<T> *tree_node<T>::find(T item)
{
    // Base case
    if (data == item)
    {
        return this;
    }

    if (data >= item)
    {
        // Traverse the left sub tree
        if (left != nullptr)
        {
            return left->find(item);
        }
        return nullptr;
    }
    else
    {
        // Traverse the right sub tree
        if (right != nullptr)
        {
            return right->find(item);
        }
        return nullptr;
    }
}

/**
 * Recursively traverse the tree using in order traversal
 * Traversal order Left, Root, Right
 */
template <typename T>
void tree_node<T>::traverse_in_order()
{
    if (left != nullptr)
    {
        left->traverse_in_order();
    }

    cout << data << "--";

    if (right != nullptr)
    {
        right->traverse_in_order();
    }
}

/**
 * Recursively traverse the tree using in pre traversal
 * Traversal order Root, Left, Right
 */
template <typename T>
void tree_node<T>::traverse_pre_order()
{

    cout << data << "--";

    if (left != nullptr)
    {
        left->traverse_in_order();
    }

    if (right != nullptr)
    {
        right->traverse_in_order();
    }
}

/**
 * Recursively traverse the tree using post order traversal
 * Traversal order Left, Right, Root
 */
template <typename T>
void tree_node<T>::traverse_post_order()
{
    if (left != nullptr)
    {
        left->traverse_in_order();
    }

    if (right != nullptr)
    {
        right->traverse_in_order();
    }

    cout << data << "--";
}
