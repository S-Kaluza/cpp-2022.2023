#include <iostream>
#include "Szablon.h"
#include <time.h>
#include "Array.h"
using namespace std;

void losujLiczby(int tab[], int x, int a, int b);
void losujZnaki(char tab[], int x, char a, char b);

int main()
{
    // testowanie funkcji sortującej
    int N = 10;
    char tab1[10];
    int tab2[10];
    cout << "Zadanie 1 - sortowanie tablicy liczb" << endl;
    losujZnaki(tab1, N, 'a', 'g');
    losujLiczby(tab2, N, 1, 10);
    cout << "Tablice:" << endl;
    wypisz(tab1, N);
    wypisz(tab2, N);
    cout << "Po sortowaniu:" << endl;
    sortuj(tab1, N);
    wypisz(tab1, N);
    sortuj(tab2, N);
    wypisz(tab2, N);
    cout << endl
         << "Zadanie 1 - wypisywanie indeksów" << endl;
    // testowanie funkcji zwracającej indeks elementu o największej wartości
    cout << "tablice: " << endl;
    losujLiczby(tab2, N, 1, 10);
    losujZnaki(tab1, N, 'a', 'z');
    wypisz(tab1, N);
    wypisz(tab2, N);
    cout << "Indeks elementu o największej wartości: " << max(tab1, N) << endl;
    cout << "Indeks elementu o najmniejszej wartości: " << min(tab2, N) << endl;

    // Zadanie 2
    cout << endl
         << "Zadanie 2" << endl;
    Array<int> a(4);
    Array<double> *b = new Array<double>(3);
    Array<char> *c = new Array<char>(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    (*b)[0] = 1.0;
    (*b)[1] = 2.0;
    (*b)[2] = 3.0;
    (*c)[0] = 'a';
    (*c)[1] = 'b';
    (*c)[2] = 'c';
    (*c)[3] = 'd';
    (*c)[4] = 'e';
    cout << a << endl;
    cout << *b << endl;
    cout << *c << endl;
    reverse(a);
    reverse(*b);
    reverse(*c);
    cout << a << endl;
    cout << *b << endl;
    cout << *c << endl;
    a.resize(2);
    b->resize(1);
    c->resize(7);
    cout << a << endl;
    cout << *b << endl;
    cout << *c << endl;
    cout << a.length() << endl;
    cout << b->length() << endl;
    cout << c->length() << endl;
    delete c;
    delete b;
    return 0;
}

// funkcja losująca x liczb z przedziała <a,b>
void losujLiczby(int tab[], int x, int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < x; i++)
        tab[i] = rand() % (b - a + 1) + a;
}

// funkcja losująca x znaków z przedziału <a,b>
void losujZnaki(char tab[], int x, char a, char b)
{
    srand(time(NULL));
    for (int i = 0; i < x; i++)
        tab[i] = rand() % (b - a + 1) + a;
}

// Path: Szablon.cpp