#include "KontoBankowe.h"
#include <iostream>

using namespace std;

// inicjalizacja licznika
int KontoBankowe::licznik = 0;

// inicjalizacja metody statycznej getLicznik
int KontoBankowe::getLicznik()
{
    return licznik;
}

// inicjalizacja konstruktora klasy KontoBankowe
KontoBankowe::KontoBankowe(string nazwaDepozytariusza, string numerKonta, double saldo)
{
    this->nazwaDepozytariusza = nazwaDepozytariusza;
    this->numerKonta = numerKonta;
    this->saldo = saldo;
    licznik++;
}

// inicjalizacja operatora =
KontoBankowe KontoBankowe::operator=(KontoBankowe konto)
{
    this->nazwaDepozytariusza = konto.nazwaDepozytariusza;
    this->numerKonta = konto.numerKonta;
    this->saldo = konto.saldo;
    return *this;
}

// inicjalizacja operatora +=
KontoBankowe KontoBankowe::operator+=(double kwota)
{
    this->saldo += kwota;
    return *this;
}

// inicjalizacja destruktora klasy KontoBankowe
KontoBankowe::~KontoBankowe()
{
    cout << "Destruktor klasy KontoBankowe" << endl;
    licznik--;
}

// inicjalizacja metody setNazwaDepozytariusza
void KontoBankowe::setNazwaDepozytariusza(string nazwaDepozytariusza)
{
    this->nazwaDepozytariusza = nazwaDepozytariusza;
}

// inicjalizacja metody setNumerKonta
void KontoBankowe::setNumerKonta(string numerKonta)
{
    this->numerKonta = numerKonta;
}

// inicjalizacja metody setSaldo
void KontoBankowe::setSaldo(double saldo)
{
    this->saldo = saldo;
}

// inicjalizacja metody pokaz
void KontoBankowe::pokaz()
{
    cout << "Nazwa depozytariusza: " << nazwaDepozytariusza << endl;
    cout << "Numer konta: " << numerKonta << endl;
    cout << "Saldo: " << saldo << endl;
}

// inicjalizacja metody wplata
void KontoBankowe::wplata(double kwota)
{
    saldo += kwota;
}

// inicjalizacja metody wyplata
void KontoBankowe::wyplata(double kwota)
{
    saldo -= kwota;
}
