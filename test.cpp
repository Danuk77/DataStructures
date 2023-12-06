#include <iostream>
#include "Array/custom_array.hpp"
#include "Array/array_list.hpp"
#include "List/singly_linked_list.hpp"
#include "List/doubly_linked_list_struct.cpp"
#include "Tree/binary_tree.hpp"
#include "math.h"
using namespace std;

int main(int argc, char *argv[])
{
    binary_tree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(8);
    tree.insert(3);

    tree.traverse(1);

    tree.remove(55);
    return 0;
}