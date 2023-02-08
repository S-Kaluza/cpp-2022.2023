#ifndef WINO_H
#define WINO_H
#include <iostream>

using namespace std;

class Wino
{
private:
    char *marka;
    char styl[20];
    int butelki;
    static int wszytkieButelki;

public:
    Wino(const char *marka = "brak", const char *styl = "brak", int butelki = 0);
    Wino(const Wino &w);
    ~Wino();
    Wino &operator=(const Wino &w);
    Wino &operator+=(int b);
    Wino &operator-=(int b);
    int ileButelek();
    static int ileWszystkichButelek();
    virtual void pokaz() const;
    friend ostream &operator<<(ostream &os, const Wino &w)
    {
        os << "Marka: " << w.marka << endl;
        os << "Styl: " << w.styl << endl;
        os << "Butelki: " << w.butelki << endl;
        return os;
    };
};

class StareWino : public Wino
{
private:
    char *nazwa;
    int rok;
    static int butelkiStaregoWina;

public:
    StareWino();
    StareWino(const char *marka, const char *styl, int butelki, const char *nazwa, int rok);
    StareWino(const StareWino &sw);
    ~StareWino();
    int ileButelek();
    static int ileButelekStaregoWina();
    StareWino &operator=(const StareWino &sw);
    virtual void pokaz() const;
    static int ileWszystkichButelek();
    friend ostream &operator<<(ostream &os, const StareWino &sw)
    {
        cout << "StareWino" << endl;
        os << (Wino &)sw;
        os << "Nazwa: " << sw.nazwa << endl;
        os << "Rok: " << sw.rok << endl;
        return os;
    };
};
#endif