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

    // Case 1 (Leaf node)
    if (is_leaf(node))
    {
        delete node;
        node = nullptr;
    }
    // Case 2 (Inner node with a single child)
    else if (remove_single_child_node(node))
    {
        // This looks ugly because its an empty body. Maybe rethink design when you are properly awake
    }
    // Case 3 (Normal inner node)
    // Find the in order successor from the right child
    else
    {
        tree_node<T> *right_subtree = node->right;

        // If the right child has no left child, simply move the leaf up the tree
        if (right_subtree->left == nullptr)
        {
            right_subtree->left = node->left;
        }
        else
        {
            remove_node_in_order(right_subtree);
            right_subtree->left = node->left;
            right_subtree->right = node->right;
        }

        node->left = nullptr;
        node->right = nullptr;
        delete node;
        node = right_subtree;
    }

    // Check if the node we deleted was the previous root of the tree
    if (parent == nullptr)
    {
        root = node;
    }
    else
    {
        // Connect the nodes togeather as the tree is disconnected after deleting
        br == LEFT ? parent->left = node : parent->right = node;
    }

    return true;
}

/**
 * Checks whether a given value is present within the tree
 * If the node is present sets reference parameter parent to point to the parent of the node containing the value and node to point to the node itself
 * @param item The item to search for
 * @param parent Reference pointer which is set to the parent of the node containing the value being searched for
 * @param node Reference pointer which is set to the node containing the value being searched for (initially points to the root of the tree)
 * @param br Enum used to indicate the relationship between the parent and the node (Left child or right child)
 * @returns True if node is found, False otherwise
 */
template <typename T>
bool binary_tree<T>::identify_node(T item, tree_node<T> *&parent, tree_node<T> *&node, branch &br)
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
            br = branch::LEFT;
        }
    }

    // The node does not exist in the tree
    return false;
}

/**
 * Checks if the given node has only a single child node. If so removes the node and moves it's child up the tree.
 * @param node The node to remove
 * @returns True if the node only has a single child, False otherwise
 */
template <typename T>
bool binary_tree<T>::remove_single_child_node(tree_node<T> *&node)
{
    tree_node<T> *temp_ptr;
    if (node->left == nullptr && node->right != nullptr)
    {
        temp_ptr = node->right;
        node->right = nullptr;
    }
    else if (node->right == nullptr && node->left != nullptr)
    {
        temp_ptr = node->left;
        node->left = nullptr;
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
 * Given a subtree, finds the inorder successor (The first node visited during in order traversal)
 * @param node Reference to the node to remove. Once removed will point to the new subtree root
 */
template <typename T>
void binary_tree<T>::remove_node_in_order(tree_node<T> *&right_subtree)
{
    tree_node<T> *right_parent = nullptr;
    // Traverse the subtree until we find the lowest value
    while (right_subtree->left != nullptr)
    {
        right_parent = right_subtree;
        right_subtree = right_subtree->left;
    }

    // Make the parent of the lowest value's left pointer point to the right of the lowest value
    right_parent->left = right_subtree->right;
    right_subtree->right = nullptr;
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