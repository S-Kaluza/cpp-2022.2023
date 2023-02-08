#include <iostream>
#include "Array.cpp"

using std::cout;
using std::endl;
using std::string;

template <typename T, int length = 0>
void Sort(T *arr)
{
    T temp;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T, int length = 0>
T *minAndMax(T *arr)
{
    T *result = new T[2];
    result[0] = arr[0];
    result[1] = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < result[0])
        {
            result[0] = arr[i];
        }
        if (arr[i] > result[1])
        {
            result[1] = arr[i];
        }
    }
    return result;
}

int main()
{
    int arr[5] = {7, 3, 3, 84, 12};
    Sort<int, 5>(arr);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    int *result = minAndMax<int, 5>(arr);
    cout << "Min: " << result[0] << endl;
    cout << "Max: " << result[1] << endl;

    Array<int> a(4);
    Array<double> *b = new Array<double>(4);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    (*b)[0] = 1.1;
    (*b)[1] = 2.2;
    (*b)[2] = 3.3;
    (*b)[3] = 4.4;
    cout << a << endl;
    delete b;
    return 0;
}