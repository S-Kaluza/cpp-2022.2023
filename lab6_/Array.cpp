#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template <typename T, int length = 0>
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
        {
            buf[i] = a.buf[i];
        }
    }
    ~Array()
    {
        delete[] buf;
    };
    T &operator[](int index)
    {
        return buf[index];
    };
    T operator[](int index) const
    {
        return buf[index];
    };
    int arrLength() const
    {
        return len;
    };
    Array<T> &operator=(const Array<T> &a)
    {
        if (this != &a)
        {
            if (len != a.len)
            {
                delete[] buf;
                len = a.len;
                buf = new T[len];
            }
            for (int i = 0; i < len; i++)
            {
                buf[i] = a.buf[i];
            }
        }
        return *this;
    };
};

template <typename T, int length>
ostream &operator<<(ostream &out, const Array<T> &a)
{
    for (int i = 0; i < a.arrLength(); i++)
    {
        out << a[i] << endl;
    }
    return out;
}

#endif