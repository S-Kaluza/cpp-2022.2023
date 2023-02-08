#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T *buf;
    int len;

public:
    Array(int size)
    {
        len = size;
        buf = new T[len];
    }

    Array(const Array<T> &a)
    {
        len = a.len;
        buf = new T[len];
        for (int i = 0; i < len; i++)
            buf[i] = a.buf[i];
    }

    ~Array()
    {
        delete[] buf;
    }

    void resize(int size)
    {
        T *temp = new T[size];
        if (len < size)
            for (int i = 0; i < len; i++)
                temp[i] = buf[i];
        else
            for (int i = 0; i < size; i++)
                temp[i] = buf[i];
        delete[] buf;
        buf = temp;
        len = size;
    }

    T &operator[](int index)
    {
        return buf[index];
    }
    int length()
    {
        return len;
    }
    Array<T> &operator=(const Array<T> &a)
    {
        if (this == &a)
            return *this;
        delete[] buf;
        len = a.len;
        buf = new T[len];
        for (int i = 0; i < len; i++)
            buf[i] = a.buf[i];
        return *this;
    }
};

template <typename T>
ostream &operator<<(ostream &o, Array<T> &a)
{
    for (int i = 0; i < a.length(); i++)
        o << a[i] << " ";
    o << endl;
    return o;
}

template <typename T>
void reverse(Array<T> &a)
{
    T temp;
    for (int i = 0; i < a.length() / 2; i++)
    {
        temp = a[i];
        a[i] = a[a.length() - i - 1];
        a[a.length() - i - 1] = temp;
    }
}

#endif