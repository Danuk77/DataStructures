using namespace std;
#pragma once

enum branch
{
    LEFT,
    RIGHT
};

template <typename T>
struct tree_node
{
    T data;
    tree_node<T> *left;
    tree_node<T> *right;

    ~tree_node();
    tree_node(T item);
    tree_node(T item, tree_node<T> *left_ptr, tree_node<T> *right_ptr);
    void update(T item);
    void update_left_subtree(tree_node<T> *left_ptr);
    void update_right_subtree(tree_node<T> *right_ptr);
    bool insert(T item);
    bool insert_at_leaf(tree_node<T> *&child, T item);
    tree_node<T> *find(T item);

    // Traversal functions
    void traverse_in_order();
    void traverse_pre_order();
    void traverse_post_order();
};

/**
 * Binary tree structure
 * Note: This structure assumes that the type being used is easily comparable using comparison operators (eg: >)
 * This has not been thoroughly tested using many types (only int, float, string, etc.)
 */
template <typename T>
struct binary_tree
{
    tree_node<T> *root;

    ~binary_tree();
    binary_tree();
    bool insert(T item);
    bool remove(T item);
    bool find(T item);
    void traverse(int method);

    // Potentially remove these functions
    bool is_leaf(tree_node<T> *&node);
    int is_inner_node_with_leaf_child(tree_node<T> *&node);
    void remove_inner_node_with_leaf_child(tree_node<T> *&node, int condition);
    void post_order_node_remove(tree_node<T> *&node);
    bool remove_from_tree(tree_node<T> *&node);

    bool identify_node(T item, tree_node<T> *&parent, tree_node<T> *&node, branch br);
    bool remove_single_child_node(tree_node<T> *&node);
    // bool find_in_order_successor(tree_node<T> *&parent, tree_node<T> *&node);
    // bool is_leaf_parent(tree_node<T> *&node);
};

// Include the actual implementations of the above structs
#include "binary_tree_node.cpp"
#include "binary_tree.cpp"