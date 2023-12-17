#include "avl_tree.hpp"

/**
 * Destructor for an avl tree
 */
template <typename T>
avl_tree<T>::~avl_tree()
{
    delete root;
}

/**
 * Default constructor for an AVL tree
 */
template <typename T>
avl_tree<T>::avl_tree() : root(nullptr)
{
}

/**
 * Insert a node into the AVL tree
 * @param item The item to insert
 * @returns True if insertion is successful, False otherwise
 */
template <typename T>
void avl_tree<T>::insert(T item)
{
    // If the tree is uninitialised
    if (root == nullptr)
    {
        root = new avl_tree_node<T>(item, nullptr, nullptr);
    }
    else
    {
        root->insert(item);
        // Balance the tree
        // root->balance(root, balancing_threshold);
    }
}

/**
 * Remove a node from the AVL tree
 * @param item The item to remove
 * @returns True if the removal is successful
 */
template <typename T>
bool avl_tree<T>::remove(T item)
{
    return true;
}

/**
 * Check if an item exist in the AVL tree
 * @param itemThe item to check for
 * @returns True if it exists, False otherwise
 */
template <typename T>
bool avl_tree<T>::find(T item)
{
    return true;
}

/**
 * Traverse the AVL tree using the specified order
 * @param method Integer used for defining the order of traversal
 *      1-In order
 *      2-Pre order
 *      3-Post order
 */
template <typename T>
void avl_tree<T>::traverse(int method)
{

    // Check if the tree is empty
    if (root == nullptr)
    {
        throw std::out_of_range("The tree is empty");
    }

    switch (method)
    {
    case 1:
        root->traverse_in_order();
        break;

    case 2:
        root->traverse_pre_order();
        break;

    case 3:
        root->traverse_post_order();
        break;

    default:
        throw std::out_of_range("The specified traversal method is invalid. Available options are 1 (In order), 2 (Pre order), 3 (Post order)");
        break;
    }

    cout << endl;
}

// struct avl_tree
// {
//     avl_tree<T> *root;
//     // Balancing threshold used for determining how much unevenness in depth between left and right subtree is allowed
//     int balancing_threshold = 1;

//     ~avl_tree();
//     avl_tree();
//     bool insert(T item);
//     bool remove(T item);
//     bool find(T item);
//     void traverse(int method);
// };
