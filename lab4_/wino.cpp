#include "wino.h"
#include <cstring>

int Wino::wszytkieButelki = 0;
int StareWino::butelkiStaregoWina = 0;

int Wino::ileWszystkichButelek()
{
    return wszytkieButelki;
}

int StareWino::ileButelekStaregoWina()
{
    return butelkiStaregoWina;
}

int StareWino::ileWszystkichButelek()
{
    return Wino::ileWszystkichButelek();
}

// definicja metody statycznej
int Wino::ileButelek()
{
    return butelki;
}

int StareWino::ileButelek()
{
    return Wino::ileButelek();
}

Wino::Wino(const char *marka, const char *styl, int butelki)
{
    this->marka = new char[strlen(marka) + 1];
    strcpy(this->marka, marka);
    strcpy(this->styl, styl);
    this->butelki = butelki;
    wszytkieButelki += butelki;
}

Wino::Wino(const Wino &w)
{
    this->marka = new char[strlen(w.marka) + 1];
    strcpy(this->marka, w.marka);
    strcpy(this->styl, w.styl);
    this->butelki = w.butelki;
    wszytkieButelki += butelki;
}

Wino::~Wino()
{
    wszytkieButelki -= butelki;
    delete[] this->marka;
}

Wino &Wino::operator=(const Wino &w)
{
    if (this == &w)
        return *this;
    delete[] this->marka;
    this->marka = new char[strlen(w.marka) + 1];
    strcpy(this->marka, w.marka);
    strcpy(this->styl, w.styl);
    this->butelki = w.butelki;
    return *this;
}

Wino &Wino::operator+=(int b)
{
    this->butelki += b;
    return *this;
}

Wino &Wino::operator-=(int b)
{
    this->butelki -= b;
    return *this;
}

void Wino::pokaz() const
{
    cout << "Marka: " << this->marka << endl;
    cout << "Styl: " << this->styl << endl;
    cout << "Butelki: " << this->butelki << endl;
}

StareWino::StareWino() : Wino()
{
    this->nazwa = new char[1];
    this->nazwa[0] = '\0';
    this->rok = 0;
    butelkiStaregoWina += this->ileButelek();
}

StareWino::StareWino(const char *marka, const char *styl, int butelki, const char *nazwa, int rok) : Wino(marka, styl, butelki)
{
    this->nazwa = new char[strlen(nazwa) + 1];
    strcpy(this->nazwa, nazwa);
    this->rok = rok;
    butelkiStaregoWina += this->ileButelek();
}

StareWino::StareWino(const StareWino &sw) : Wino(sw)
{
    this->nazwa = new char[strlen(sw.nazwa) + 1];
    strcpy(this->nazwa, sw.nazwa);
    this->rok = sw.rok;
    butelkiStaregoWina += this->ileButelek();
}

StareWino::~StareWino()
{
    delete[] this->nazwa;
}

StareWino &StareWino::operator=(const StareWino &sw)
{
    if (this == &sw)
        return *this;
    Wino::operator=(sw);
    delete[] this->nazwa;
    this->nazwa = new char[strlen(sw.nazwa) + 1];
    strcpy(this->nazwa, sw.nazwa);
    this->rok = sw.rok;
    return *this;
}

void StareWino::pokaz() const
{
    Wino::pokaz();
    cout << "Nazwa: " << this->nazwa << endl;
    cout << "Rok: " << this->rok << endl;
}