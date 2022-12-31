#include "Punkt.h"
#include <iostream>

// inicjalizacja licznika
int Punkt::licznik = 0;

// inicjalizacja metody statycznej getLicznik
int Punkt::getLicznik()
{
    return licznik;
}

// inicjalizacja konstruktora domyślnego klasy Punkt
Punkt::Punkt()
{
    this->x = 0;
    this->y = 0;
    licznik++;
}

// inicjalizacja konstruktora klasy Punkt
Punkt::Punkt(double x, double y)
{
    this->x = x;
    this->y = y;
    licznik++;
}

// inicjalizacja konstruktora klasy Punkt z parametrem nazwa
Punkt::Punkt(char nazwa, double x, double y)
{
    this->nazwa = nazwa;
    this->x = x;
    this->y = y;
    licznik++;
}

// inicjalizacja konstruktora kopiującego klasy Punkt
Punkt::Punkt(const Punkt &punkt)
{
    this->x = punkt.x;
    this->y = punkt.y;
}

// inicjalizacja destruktora klasy Punkt
Punkt::~Punkt()
{
    std::cout << "Destruktor klasy Punkt" << std::endl;
}

// inicjalizacja operatora =
Punkt Punkt::operator=(Punkt punkt)
{
    this->x = punkt.x;
    this->y = punkt.y;
    return *this;
}

// inicjalizacja operatora +
Punkt Punkt::operator+(Punkt punkt)
{
    Punkt nowyPunkt(this->x + punkt.x, this->y + punkt.y);
    return nowyPunkt;
}

// inicjalizacja metody przesun
void Punkt::przesun(double x, double y)
{
    this->x += x;
    this->y += y;
}

// inicjalizacja metody skaluj
void Punkt::skaluj(double skala)
{
    this->x *= skala;
    this->y *= skala;
}

// inicjalizacja metody odcieta
double Punkt::odcieta()
{
    return this->x;
}

// inicjalizacja metody rzedna
double Punkt::rzedna()
{
    return this->y;
}