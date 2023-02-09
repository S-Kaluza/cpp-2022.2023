#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <math.h>
#include <set>

using std::back_inserter;
using std::cin;
using std::copy_if;
using std::cout;
using std::endl;
using std::for_each;
using std::list;
using std::set;
using std::string;
using std::vector;

// zadanie 1
struct para
{
    char a;
    int b;
};

// zadanie 2
struct point
{
    int x;
    int y;
    int R;
    int G;
    int B;
    string nazwa;
};
// funkcje do zadań
int getNumberOfQuarter(point);
int *numberOfUse(vector<int>);
set<int> getMostCommonNumbers(vector<int>);

// definicje funkcji do zadania 1
bool operator<(const para &lhs, const para &rhs)
{
    return lhs.b < rhs.b;
}

bool mniejszeNiz(const para &lhs, const para &rhs)
{
    return lhs.b < rhs.b;
}

bool wypelnijPare(para &p)
{
    std::cin >> p.a >> p.b;
    return p.a != '0';
}

void wypiszPare(const para &p)
{
    std::cout << p.a << " " << p.b << std::endl;
}

// definicje warunków do zadania 2
bool luminacja(const point &p1, const point &p2)
{
    double l1 = 0.3 * p1.R + 0.59 * p1.G + 0.11 * p1.B;
    double l2 = 0.3 * p2.R + 0.59 * p2.G + 0.11 * p2.B;
    return l1 < l2;
}

bool darkPoint(const point &p)
{
    double l = 0.3 * p.R + 0.59 * p.G + 0.11 * p.B;
    return l < 64;
}

// funkcja main
int main()
{
    // lista punktów do zadania 2
    list<point> lista{
        {-81, 5, 0, 0, 0, "black"},
        {1, -23, 255, 0, 0, "red"},
        {1, 4, 0, 255, 0, "green"},
        {13, 1, 0, 0, 255, "blue"},
        {3, 80, 255, 255, 0, "yellow"},
        {30, 7, 255, 0, 255, "magenta"},
        {3, -76, 0, 255, 255, "cyan"},
        {-2, 90, 255, 255, 255, "white"},
        {-2, -10, 0, 0, 0, "black"},
        {2, -11, 255, 0, 0, "red"},
        {2, 12, 0, 255, 0, "green"},
        {-2, 13, 0, 0, 255, "blue"},
        {4, 14, 255, 255, 0, "yellow"},
        {4, -15, 255, 0, 255, "magenta"},
        {4, -16, 0, 255, 255, "cyan"},
        {4, 17, 255, 255, 255, "white"},
        {-4, 28, 0, 255, 0, "green"}};
    // lista.remove_if([](const point &p)
    //                 { return p.nazwa.length() > 5; });

    //  --  zadanie 1 --
    // para p;
    // vector<para> v;
    // while (wypelnijPare(p))
    // {
    //     v.push_back(p);
    //     while (wypelnijPare(p))
    //     {
    //         v.push_back(p);
    //     }
    // }
    // for_each(v.begin(), v.end(), wypiszPare);
    // // sort(v.begin(), v.end() - v.size() + 3, mniejszeNiz);
    // // for_each(v.begin(), v.end(), wypiszPare);
    // sort(v.begin(), v.end(), operator<);
    // for_each(v.begin(), v.end(), wypiszPare);

    // --  zadanie 2 --
    int IQ = 0;
    int IIQ = 0;
    int IIIQ = 0;
    int IVQ = 0;
    for (point p : lista)
    {
        if (getNumberOfQuarter(p) == 1)
        {
            IQ++;
        }
        else if (getNumberOfQuarter(p) == 2)
        {
            IIQ++;
        }
        else if (getNumberOfQuarter(p) == 3)
        {
            IIIQ++;
        }
        else if (getNumberOfQuarter(p) == 4)
        {
            IVQ++;
        }
    }
    cout << endl
         << "przed sortowaniem: " << endl;
    for (point p : lista)
    {
        cout << p.nazwa << endl;
    }
    lista.sort(luminacja);
    cout << endl
         << "po sortowaniu: " << endl;
    for (point p : lista)
    {
        cout << p.nazwa << endl;
    }

    list<point> darkPoints;
    copy_if(lista.begin(), lista.end(), back_inserter(darkPoints), darkPoint);
    cout << endl
         << "ilosc ciemnych punktow: " << darkPoints.size() << endl;
    cout << "I ćwiartka: " << IQ << endl;
    cout << "II ćwiartka: " << IIQ << endl;
    cout << "III ćwiartka: " << IIIQ << endl;
    cout << "IV ćwiartka: " << IVQ << endl;
    // --  zadanie 3 --
    int number = 0;
    vector<int> v;
    while (cin >> number)
    {
        if (number == 0)
            break;
        v.push_back(number);
    }
    cout << endl;
    set<int> mostCommonNumbers = getMostCommonNumbers(v);
    for (auto &i : mostCommonNumbers)
    {
        cout << i << " ";
    }
    return 0;
}

int getNumberOfQuarter(point p)
{
    if (p.x > 0 && p.y > 0)
    {
        return 1;
    }
    else if (p.x < 0 && p.y > 0)
    {
        return 2;
    }
    else if (p.x < 0 && p.y < 0)
    {
        return 3;
    }
    else if (p.x > 0 && p.y < 0)
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

int *numberOfUse(vector<int> v)
{
    int *numberOfUse = new int[v.size()];
    for (int i = 0; i < (int)v.size(); i++)
    {
        numberOfUse[i] = 0;
    }
    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = 0; j < (int)v.size(); j++)
        {
            if (v[i] == v[j])
            {
                numberOfUse[i]++;
            }
        }
    }
    return numberOfUse;
}

set<int> getMostCommonNumbers(vector<int> v)
{
    int *numberOfUse = new int[v.size()];
    for (int i = 0; i < (int)v.size(); i++)
    {
        numberOfUse[i] = 0;
    }
    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = 0; j < (int)v.size(); j++)
        {
            if (v[i] == v[j])
            {
                numberOfUse[i]++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (numberOfUse[i] > max)
        {
            max = numberOfUse[i];
        }
    }
    set<int> mostCommonNumbers;
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (numberOfUse[i] == max)
        {
            mostCommonNumbers.insert(v[i]);
        }
    }
    return mostCommonNumbers;
}