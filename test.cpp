#include <iostream>
#include "Array/custom_array.hpp"
#include "Array/array_list.hpp"
#include "List/singly_linked_list.hpp"
#include "List/doubly_linked_list_struct.cpp"
#include "Tree/binary_tree.hpp"
#include "Tree/avl_tree.hpp"
#include "math.h"
using namespace std;

int main(int argc, char *argv[])
{
    avl_tree<int> tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    tree.traverse(1);

    // Testing tree traversals
    // cout << "In order traversal" << endl;
    // tree.traverse(1);

    // cout << "Pre order traversal" << endl;
    // tree.traverse(2);

    // cout << "Post order traversal" << endl;
    // tree.traverse(3);

    // tree.remove(8);

    // tree.traverse(1);

    return 0;
}