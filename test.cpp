#include <iostream>
#include ".\Array\custom_array.cpp"
#include ".\Array\array_list.hpp"
using namespace std;

void print(int val)
{
    cout << val << endl;
}

int main(int argc, char *argv[])
{
    // Instantiate a custom array
    // CustomArray<int> array(5);
    // array.visualise();
    // print(array[4]);
    // array[4] = 10;
    // array.visualise();

    ArrayList<int> list(10);
    list.visualise();
    return 0;
}