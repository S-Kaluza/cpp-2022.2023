#include "Okno.h"
#include <iostream>

using std::cout;
using std::endl;

Okno::Okno(int szerokosc, int wysokosc)
{
    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;
}

void Okno::rysuj()
{
    for (int i = 0; i < this->wysokosc; i++)
    {
        for (int j = 0; j < this->szerokosc; j++)
        {
            if (i == 0 || i == this->wysokosc - 1)
                cout << "*";
            else if (j == 0 || j == this->szerokosc - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

OknoZRamka::OknoZRamka(int szerokosc, int wysokosc, int gruboscRamki) : Okno(szerokosc, wysokosc)
{
    this->gruboscRamki = gruboscRamki;
}

void OknoZRamka::rysuj()
{
    for (int i = 0; i < this->wysokosc + this->gruboscRamki * 2; i++)
    {
        if (i < this->gruboscRamki || i >= this->wysokosc + this->gruboscRamki)
        {
            for (int j = 0; j < this->szerokosc + this->gruboscRamki * 2; j++)
                cout << "*";
        }
        else
        {
            for (int j = 0; j < this->szerokosc + this->gruboscRamki * 2; j++)
            {
                if (j < this->gruboscRamki || j >= this->szerokosc + this->gruboscRamki)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}

OknoZMenu::OknoZMenu(int szerokosc, int wysokosc, int ile) : Okno(szerokosc, wysokosc)
{
    this->ile = ile;
}

void OknoZMenu::rysuj()
{
    char znak = 'a' - 1;
    int licznik = 0;
    for (int i = 0; i < this->wysokosc; i++)
    {
        for (int j = 0; j < this->szerokosc; j++)
        {
            if (i == 0 || i == this->wysokosc - 1)
                cout << "*";
            else if (j == 0 || j == this->szerokosc - 1)
                cout << "*";
            else if (j == 2 && this->wysokosc >= this->ile + 1 && licznik < this->ile)
                cout << (char)znak;
            else if (j == 3 && this->wysokosc >= this->ile + 1 && licznik < this->ile)
                cout << ")";
            else
                cout << " ";
        }
        znak++;
        licznik++;
        cout << endl;
    }
    if (this->wysokosc < this->ile + 1)
    {
        cout << "Menu: " << endl;
        for (int i = 0; i < this->ile; i++)
            cout << (char)znak++ << ")" << endl;
    }
}

OknoZMenuZRamka::OknoZMenuZRamka(int szerokosc, int wysokosc, int ile, string tytul) : OknoZMenu(szerokosc, wysokosc, ile)
{
    this->tytul = tytul;
}

void OknoZMenuZRamka::rysuj()
{
    char znak = 'a';
    int licznik = 0;
    for (int i = 0; i < this->wysokosc + 2; i++)
    {
        if (i == 0 || i == this->wysokosc + 1)
        {
            for (int j = 0; j < this->szerokosc + 2; j++)
                cout << "*";
        }
        else
        {
            for (int j = 0; j < this->szerokosc + 2; j++)
            {
                if (j == 0 || j == this->szerokosc + 1)
                    cout << "*";
                else if (j == 2 && this->wysokosc >= this->ile + 1 && licznik < this->ile)
                    cout << (char)znak;
                else if (j == 3 && this->wysokosc >= this->ile + 1 && licznik < this->ile)
                    cout << ")";
                else
                    cout << " ";
            }
            znak++;
            licznik++;
        }
        cout << endl;
    }
    if (this->wysokosc < this->ile + 1)
    {
        cout << "Menu: " << endl;
        for (int i = 0; i < this->ile; i++)
            cout << (char)znak++ << ")" << endl;
    }
}