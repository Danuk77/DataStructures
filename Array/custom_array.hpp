#pragma once
template <typename T>

class CustomArray
{
private:
    int size;
    T *data;

public:
    ~CustomArray();
    CustomArray(int size);
    CustomArray(T *items, int size);
    bool insert(T item, int index);
    void visualise();
    T index(int index);
    int length();

    // Operator overloading
    T &operator[](int index);
    T operator[](int index) const;
};