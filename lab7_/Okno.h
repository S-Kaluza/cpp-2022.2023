#ifndef OKNO_H
#define OKNO_H

#include <iostream>

using std::string;
class Okno
{
protected:
    int szerokosc;
    int wysokosc;

public:
    Okno(int szerokosc, int wysokosc);
    void rysuj();
};

class OknoZRamka : public Okno
{
private:
    int gruboscRamki;

public:
    OknoZRamka(int szerokosc, int wysokosc, int gruboscRamki);
    void rysuj();
};

class OknoZMenu : public Okno
{
protected:
    int ile;

public:
    OknoZMenu(int szerokosc, int wysokosc, int ile);
    void rysuj();
};

class OknoZMenuZRamka : public OknoZMenu
{
protected:
    string tytul;

public:
    OknoZMenuZRamka(int szerokosc, int wysokosc, int ile, string tytul);
    void rysuj();
};

#endif