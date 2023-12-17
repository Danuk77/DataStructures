#include "avl_tree.hpp"
/**
 * Destructor for an AVL tree node
 */
template <typename T>
avl_tree_node<T>::~avl_tree_node()
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
 * Default constructor for a self balancing AVL tree node
 */
template <typename T>
avl_tree_node<T>::avl_tree_node(T item) : data(item), height(0)
{
}

/**
 * Constructor for a self balancing AVL tree node
 */
template <typename T>
avl_tree_node<T>::avl_tree_node(T item, avl_tree_node<T> *left_ptr, avl_tree_node<T> *right_ptr) : data(item), left(left_ptr), right(right_ptr)
{
    if (left == nullptr && right == nullptr)
    {
        height = 0;
    }
    else if (left == nullptr)
    {
        height = right->height + 1;
    }
    else if (right == nullptr)
    {
        height = left->height + 1;
    }
    else
    {
        height = max(left->height, right->height) + 1;
    }
}

/**
 * Insert a new item into the avl tree
 * Re-evaluates the heights of each nodes after a successfull insertion
 * @param item The item to insert
 * @returns An integer which represents the height of the subtree
 */
template <typename T>
avl_tree_node<T> *avl_tree_node<T>::insert(T item, avl_tree_node<T> *ref, int balance_threshold)
{
    if (data >= item)
    {
        if (left == nullptr)
        {
            left = new avl_tree_node(item, nullptr, nullptr);
        }
        else
        {
            left = left->insert(item, left, balance_threshold);
        }
    }
    else
    {
        if (right == nullptr)
        {
            right = new avl_tree_node(item, nullptr, nullptr);
        }
        else
        {
            right = right->insert(item, right, balance_threshold);
        }
    }

    height = calculate_height(this);

    // Balance the tree
    return balance(balance_threshold);
}

/**
 * Recursively balances the nodes in the avl tree
 * @param ref The subtree root to balance
 */
template <typename T>
avl_tree_node<T> *avl_tree_node<T>::balance(int balance_treshold)
{
    // Calculate the balance of the subtree rooted at ref
    int left_height = left == nullptr ? -1 : left->height;
    int right_height = right == nullptr ? -1 : right->height;

    int subtree_balance = left_height - right_height;

    // Check if the subtree is out of balance
    if (subtree_balance > balance_treshold)
    {
        // Identify whether we must do a right rotation or a left-right rotation
        if (left->right == nullptr)
        {
            return right_rotate();
        }
        else
        {
            return left_right_rotate();
        }
    }
    else if (subtree_balance < -balance_treshold)
    {
        // Identify whether we must do a left rotation or a right-left rotation
        if (right->left == nullptr)
        {
            return left_rotate();
        }
        else
        {
            return right_left_rotate();
        }
    }

    return this;
}

/**
 * Rotate the subtree in the left direction
 */
template <typename T>
avl_tree_node<T> *avl_tree_node<T>::left_rotate()
{
    avl_tree_node<T> *temp = right;
    right = right->left;
    temp->left = this;

    // Adjust the heights
    height = calculate_height(this);
    temp->height = calculate_height(temp);

    return temp;
}

/**
 * Rotate the subtree in the right direction
 */
template <typename T>
avl_tree_node<T> *avl_tree_node<T>::right_rotate()
{
    avl_tree_node<T> *temp = left;
    left = left->right;
    temp->right = this;

    // Adjust the heights
    height = calculate_height(this);
    temp->height = calculate_height(temp);

    return temp;
}

/**
 * Do a left right rotation
 * @param ref The root of the subtree
 */
template <typename T>
avl_tree_node<T> *avl_tree_node<T>::left_right_rotate()
{
    left = left->left_rotate();
    return right_rotate();
}

/**
 * Do a right left rotation
 * @param ref The root of the subtree
 */
template <typename T>
avl_tree_node<T> *avl_tree_node<T>::right_left_rotate()
{
    right = right->right_rotate();
    return left_rotate();
}

/**
 * Function to calcuate the height of a node
 * @param ref The node to find the height of
 * @returns The height of the node
 */
template <typename T>
int avl_tree_node<T>::calculate_height(avl_tree_node *ref)
{
    // If the node has both children
    if (ref->left != nullptr && ref->right != nullptr)
    {
        return max(ref->left->height, ref->right->height) + 1;
    }
    // If the node only has a left child
    else if (ref->left != nullptr)
    {
        return ref->left->height + 1;
    }
    // If the node only has a right child
    else if (ref->right != nullptr)
    {
        return ref->right->height + 1;
    }
    // If the node is a leaf
    else
    {
        return 0;
    }
}

/**
 * Recursively traverse the tree using in order traversal
 * Traversal order Left, Root, Right
 */
template <typename T>
void avl_tree_node<T>::traverse_in_order()
{
    if (left != nullptr)
    {
        left->traverse_in_order();
    }

    cout << " node " << data << " Height " << height << endl;

    if (right != nullptr)
    {
        right->traverse_in_order();
    }
}

/**
 * Recursively traverse the tree using pre order traversal
 * Traversal order Root, Left, Right
 */
template <typename T>
void avl_tree_node<T>::traverse_pre_order()
{

    cout << data << "--";

    if (left != nullptr)
    {
        left->traverse_pre_order();
    }

    if (right != nullptr)
    {
        right->traverse_pre_order();
    }
}

/**
 * Recursively traverse the tree using post order traversal
 * Traversal order Left, Right, Root
 */
template <typename T>
void avl_tree_node<T>::traverse_post_order()
{
    if (left != nullptr)
    {
        left->traverse_post_order();
    }

    if (right != nullptr)
    {
        right->traverse_post_order();
    }

    cout << data << "--";
}
