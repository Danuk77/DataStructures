#include <algorithm>
using namespace std;
#pragma once

template <typename T>
struct avl_tree_node
{
    T data;
    avl_tree_node<T> *left = nullptr;
    avl_tree_node<T> *right = nullptr;
    int height;

    ~avl_tree_node();
    avl_tree_node(T item);
    avl_tree_node(T item, avl_tree_node<T> *left_ptr, avl_tree_node<T> *right_ptr);

    avl_tree_node *insert(T item, avl_tree_node *ref, int balance_threshold);
    avl_tree_node *balance(int balance_threshold);

    // Rotations involved in balancing
    avl_tree_node<T> *left_rotate();
    avl_tree_node<T> *right_rotate();
    avl_tree_node<T> *left_right_rotate();
    avl_tree_node<T> *right_left_rotate();

    // Other helper functions
    int calculate_height(avl_tree_node *ref);

    // Traversal functions
    void traverse_in_order();
    void traverse_pre_order();
    void traverse_post_order();
};

/**
 * Self balancing tree structure (AVL tree)
 */
template <typename T>
struct avl_tree
{
    avl_tree_node<T> *root;
    // Balancing threshold used for determining how much unevenness in depth between left and right subtree is allowed
    int balancing_threshold = 1;

    ~avl_tree();
    avl_tree();

    void insert(T item);
    bool remove(T item);
    bool find(T item);
    void traverse(int method);
};

#include "avl_tree_node.cpp"
#include "avl_tree.cpp"
