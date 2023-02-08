#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

struct Para
{
    int a;
    int b;
};

bool operator>(Para const &lhs, Para const &rhs)
{
    return lhs.a > rhs.a;
}

bool MniejszeNiz(Para const &lhs, Para const &rhs)
{
    return lhs.a < rhs.a;
}

bool WypelnijPare(Para &para)
{
    cout << "Liczba 1: ";
    cin >> para.a;
    cout << "Liczba 2: ";
    cin >> para.b;
    return para.a != 0 || para.b != 0;
}

void WypiszPare(Para &para)
{
    cout << para.a << " " << para.b << std::endl;
}

int main()
{
    Para para;
    std::vector<Para> vec_Para;
    while (WypelnijPare(para))
    {
        vec_Para.push_back(para);
    }
    std::sort(vec_Para.begin(), vec_Para.end(), MniejszeNiz);
    cout << "Wypisuje posortowane" << endl;
    for_each(vec_Para.begin(), vec_Para.end(), WypiszPare);
}
