#include "binary_tree.hpp"

/**
 * Destructor for the binary tree
 */
template <typename T>
binary_tree<T>::~binary_tree()
{
    // Traverse the tree in post order traversal and free the memory on the traversal back
    // This logic is defined inside the destructor for the node
    delete root;
}

/**
 * Default constructor for a binary tree
 */
template <typename T>
binary_tree<T>::binary_tree() : root(nullptr)
{
}

/**
 * Add an item to the binary tree
 * @param item The item to be added
 */
template <typename T>
bool binary_tree<T>::insert(T item)
{
    // Check if the tree is empty
    if (root == nullptr)
    {
        root = new tree_node<T>(item, nullptr, nullptr);
        return true;
    }

    return root->insert(item);
}

/**
 * Remove an item from the binary tree
 * This is a wrapper function that does the initial checks and calls the function 'remove_from_tree' which handles the removal
 * @param item The item to be removed
 */
template <typename T>
bool binary_tree<T>::remove(T item)
{
    // Check if the tree is empty
    if (root == nullptr)
    {
        throw std::out_of_range("The tree is empty");
    }

    // Check whether the value exist within the tree
    tree_node<T> *parent = nullptr;
    tree_node<T> *node = root;
    branch br;

    if (!identify_node(item, parent, node, br))
    {
        throw std::out_of_range("The item is not present in the tree");
    }

    // Check which case the node to delete falls under
    // Case 1 (Leaf node)
    if (is_leaf(node))
    {
        delete node;
        node == nullptr;
    }
    // Case 2 (Inner node with a single child)
    else if (remove_single_child_node(node) != nullptr)
    {
        // This looks ugly because its an empty body. Maybe rethink design when you are properly awake
    }
    // Case 3 (Normal inner node)
    // Find the in order successor from the right child
    else
    {
        tree_node<T> *in_succ;
        tree_node<T> *in_succ_parent;
        }
    // TODO: Check if the node we deleted was the root of the tree
    return true;
}

// Removes a node from the tree
// Three cases
// 1. Leaf node => Simply remove the node
// 2. Inner node with one leaf => Move the leaf upwards in the tree and delete the current node
// 3. Inner nodes => Replace with another node (from the left side -> maximum value, from the right side -> minimum value) and delete that node
//                      Same as finding the in order successor and replacing the node with it
template <typename T>
bool binary_tree<T>::remove_from_tree(tree_node<T> *&node)
{
    // First base case
    // If the node to remove is a leaf, simply remove it from the tree
    if (is_leaf(node))
    {
        delete node;
        return true;
    }

    // Second base case
    // If the node to remove is an inner node with atleast one leaf child (immediately)
    int has_leaf_child = is_inner_node_with_leaf_child(node);

    if (has_leaf_child != -1)
    {
        remove_inner_node_with_leaf_child(node, has_leaf_child);
        return true;
    }

    // General case
    // If the node is an inner node with no leaf children
    // Traverse the subtree using post order traversal and find the first leaf node it visits and make that node the new root of the subtree
    post_order_node_remove(node);
    return true;
}

// bool identify_node(tree_node<T> *&parent, tree_node<T> *&node);
// bool find_in_order_successor(tree_node<T> *&parent, tree_node<T> *&node);
// bool is_leaf_parent(tree_node<T> *&node);

/**
 * Checks whether a given value is present within the tree
 * If the node is present sets reference parameter param to point to the parent of the node containing the value and node to point to the node containg
 * value
 * @param item The item to search for
 * @param parent Reference pointer which is set to the parent of the node containing the value being searched for
 * @param node Reference pointer which is set to the node containing the value being searched for (initially points to the root of the tree)
 * @param br Enum used to indicate the relationship between the parent and the node (Left child or right child)
 * @returns True if node is found, False otherwise
 */
template <typename T>
bool binary_tree<T>::identify_node(T item, tree_node<T> *&parent, tree_node<T> *&node, branch br)
{
    while (node != nullptr)
    {
        // The value is found
        if (node->data == item)
        {
            return true;
        }

        // The value is not found, and we need to traverse further down into the tree
        parent = node;

        if (item > node->data)
        {
            node = node->right;
            br = branch::RIGHT;
        }
        else
        {
            node = node->left;
            br = branch::RIGHT;
        }
    }

    // The node does not exist in the tree
    return false;
}

/**
 * Checks if the given node has a single child. If so removes the node and moves it's child up the tree.
 * @param node The node to remove
 * @returns True if the node only has a single child, False otherwise
 */
template <typename T>
bool binary_tree<T>::remove_single_child_node(tree_node<T> *&node)
{
    tree_node<T> *temp_ptr;
    if (node->left == nullptr && node->right != nullptr)
    {
        node->right = nullptr;
        temp_ptr = node->right;
    }
    else if (node->right == nullptr && node->left != nullptr)
    {
        node->left = nullptr;
        temp_ptr = node->left;
    }
    else
    {
        return false;
    }

    delete node;
    node = temp_ptr;
    return true;
}

/**
 * Checks if a given node is a leaf
 * @param node The node to check if it is a leaf
 * @returns True -> If it is a leaf, False otherwise
 */
template <typename T>
bool binary_tree<T>::is_leaf(tree_node<T> *&node)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Checks if the given node is an inner node with at least one child who is a leaf
 * @param node The node to check the above condition
 * @return 0, 1 or -1. 0 if left node is a leaf, 1 if right node is a leaf and -1 if the node is has no leaf childs.
 */
template <typename T>
int binary_tree<T>::is_inner_node_with_leaf_child(tree_node<T> *&node)
{
    if (node->left != nullptr && is_child(node->left))
    {
        return 0;
    }
    else if (node->right != nullptr && is_child(node->right))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/**
 * Remove a node from the tree which falls under the following condition
 * If the node has atleast one child who is a leaf
 * @param node The node to remove
 * @param condition An integer indicating a child who is a leaf (0 for left, 1 for right)
 */
template <typename T>
void binary_tree<T>::remove_inner_node_with_leaf_child(tree_node<T> *&node, int condition)
{
    tree_node<T> *new_sub_tree_root;
    if (condition == 0)
    {
        new_sub_tree_root = node->left;
        new_sub_tree_root->right = node->right;
    }
    else
    {
        new_sub_tree_root = node->right;
        new_sub_tree_root->left = node->left;
    }

    node->left = nullptr;
    node->right = nullptr;
    delete node;
    node = new_sub_tree_root;
}

/**
 * Given a sub tree, find the first node visited during post order traversal and set that node as the root
 * @param node The subtree root
 */
template <typename T>
void binary_tree<T>::post_order_node_remove(tree_node<T> *&node)
{
    tree_node<T> *traverse_node = node;
    tree_node<T> *traverse_node_parent = nullptr;

    // Find the first leaf node visited in post order traversal
    while (!is_leaf(traverse_node))
    {
        traverse_node_parent = traverse_node;

        if (traverse_node->left != nullptr)
        {
            traverse_node = traverse_node->left;
        }
        else
        {
            traverse_node = traverse_node->right;
        }
    }

    // Make the first leaf node the new root of the subtree
    traverse_node->right = node->right;
    traverse_node->left = node->left;

    // Delink the first leaf node from its parent
    if (traverse_node_parent->left == nullptr)
    {
        traverse_node_parent->right = nullptr;
    }
    else
    {
        traverse_node_parent->left = nullptr;
    }

    // Delink the existing tree root
    node->left = nullptr;
    node->right = nullptr;

    // Free the existing tree root
    delete node;

    // Make the pointer 'node' point to our new subtree root
    node = traverse_node;
}

/**
 * Find if a value exist in the binary tree
 * @param item The value to be searched through the binary tree
 */
template <typename T>
bool binary_tree<T>::find(T item)
{
    if (root == nullptr)
    {
        throw std::out_of_range("The tree is empty");
    }

    return root->find(item);
}

/**
 * Traverse the tree using the specified order
 * @param method Integer used for defining the order of traversal
 *      1-In order
 *      2-Pre order
 *      3-Post order
 */
template <typename T>
void binary_tree<T>::traverse(int method)
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