#pragma once
template <typename T>

class ArrayList
{
private:
    int size;
    T *data;

public:
    ~ArrayList();
    ArrayList(int size);
    ArrayList(T *items, int size);
    bool append(T item, int index);
    bool remove(int index);
    bool remove(T item);
    void visualise();
    T index(int index);
    int length();

    // Operator overloading
    T &operator[](int index);
    T operator[](int index) const;
};