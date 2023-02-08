#include <iostream>
#include "wino.h"
#include "dziedziczenie.cpp"

using namespace std;

int main()
{
    Wino *tab[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Podaj numer: " << i << endl;
        if (i % 2 == 0)
        {
            tab[i] = new Wino("Wino", "Styl", 10);
        }
        else
        {
            tab[i] = new StareWino("Wino", "Styl", 10, "Nazwa", 1999);
        }
    }
    cout << "Wypisuje obiekty za pomocą metody pokaz: " << endl;
    for (int i = 0; i < 5; i++)
    {
        tab[i]->pokaz();
        cout << endl;
    }
    cout << "Wypisuje obiekty za pomocą operatora <<: " << endl;

    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
        {
            cout << static_cast<const Wino &>(*tab[i]);
        }
        else
        {
            cout << static_cast<const StareWino &>(*tab[i]);
        }

        cout << endl;
    }

    StareWino sw;
    Wino mw;
    sw = static_cast<const StareWino &>(*tab[3]);
    mw = static_cast<const Wino &>(*tab[2]);

    cout << "stare wino: " << endl
         << sw;
    cout << "nowe wino: " << endl
         << mw;

    cout << "wszystkie butelki: " << Wino::ileWszystkichButelek() << endl;
    cout << "wszystkie butelki starego wina: " << StareWino::ileButelekStaregoWina() << endl;
    DyrektorHandlowy *dh = new DyrektorHandlowy("Lis");
    dh->wypisz();
    delete[] * tab;
    return 0;
}