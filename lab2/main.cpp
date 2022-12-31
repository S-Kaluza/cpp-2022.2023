#include <iostream>
#include "KontoBankowe.h"
#include "Punkt.h"
#include <math.h>

using namespace std;

// deklaracja funkcji pokazKonta
void pokazKonta(KontoBankowe *tablica[], int n);
// deklaracja funkcji drukuj
void drukuj(Punkt);

// funkcja main - punkt wejścia do programu
int main()
{
    // inicjalizacja trzech zmiennych typu KontoBankowe

    KontoBankowe ob1 = KontoBankowe("Jan Kowalski", "1234567890", 1000);
    KontoBankowe ob2 = KontoBankowe("Anna Nowak", "0987654321", 2000);
    KontoBankowe ob3 = KontoBankowe("Janusz Kowalski", "83746592716", 3000);
    // deklaracja  tablicy trzech wskaźników do obiektów typu KontoBankowe
    KontoBankowe *tablica[3];

    // przypisanie adresów obiektów do tablicy
    tablica[0] = &ob1;
    tablica[1] = &ob2;
    tablica[2] = &ob3;

    // wywołanie metody pokaz dla każdego obiektu
    cout << "Stan poczatkowy kont:" << endl;
    pokazKonta(tablica, 3);
    cout << "______________________________________________________" << endl;

    // wywołanie metody wplata dla każdego obiektu
    cout << "Wplata 100 zl na kazde konto:" << endl;
    for (int i = 0; i < 3; i++)
    {
        tablica[i]->wplata(100);
    }

    // wywołanie metody pokaz dla każdego obiektu
    pokazKonta(tablica, 3);
    cout << endl;

    // wywołanie metody wyplata dla każdego obiektu
    cout << "Wyplata 50 zl z kazdego konta:" << endl;
    for (int i = 0; i < 3; i++)
    {
        tablica[i]->wyplata(50);
    }

    // wywołanie metody pokaz dla każdego obiektu
    pokazKonta(tablica, 3);
    cout << endl;

    // wywołanie metody setNazwaDepozytariusza dla każdego obiektu
    cout << "Zmiana nazwy depozytariusza na Jan Kowalski:" << endl;
    for (int i = 0; i < 3; i++)
    {
        tablica[i]->setNazwaDepozytariusza("Jan Kowalski");
    }

    // wywołanie metody pokaz dla każdego obiektu
    pokazKonta(tablica, 3);
    cout << endl;

    // wywołanie metody setNumerKonta dla każdego obiektu
    cout << "Zmiana numeru konta na 1234567890:" << endl;
    for (int i = 0; i < 3; i++)
    {
        tablica[i]->setNumerKonta("1234567890");
    }

    // wywołanie metody pokaz dla każdego obiektu
    pokazKonta(tablica, 3);
    cout << endl;

    // wywołanie metody setSaldo dla każdego obiektu
    cout << "Zmiana salda na 1000:" << endl;
    for (int i = 0; i < 3; i++)
    {
        tablica[i]->setSaldo(1000);
    }

    // wywołanie metody pokaz dla każdego obiektu
    pokazKonta(tablica, 3);
    cout << endl;

    // pokazanie liczby obiektów
    cout << "Liczba obiektow: " << KontoBankowe::getLicznik() << endl;
    cout << "______________________________________________________" << endl;
    cout << "Koniec czesci pierwszej" << endl
         << endl;
    cout << "______________________________________________________" << endl;
    cout << "Czesc druga" << endl
         << endl;

    // deklaracja tablicy trzech zmiennych typu Punkt
    Punkt tablicaPunktow[3];
    for (int i = 0; i < 3; i++)
    {
        tablicaPunktow[i] = Punkt(i, i);
    }

    // wywołanie funkcji drukuj dla każdego obiektu
    cout << "Stan początkowy punktow:" << endl;
    for (int i = 0; i < 3; i++)
    {
        drukuj(tablicaPunktow[i]);
    }
    cout << "______________________________________________________" << endl;

    // wywołanie metody przesun dla każdego obiektu
    cout << "Przesuniecie punktow o 1 w prawo i 1 w doł:" << endl;
    for (int i = 0; i < 3; i++)
    {
        tablicaPunktow[i].przesun(1, -1);
    }

    // wywołanie funkcji drukuj dla każdego obiektu
    for (int i = 0; i < 3; i++)
    {
        drukuj(tablicaPunktow[i]);
    }
    cout << endl;

    // wywołanie metody skaluj dla każdego obiektu
    cout << "Skalowanie punktow o 2:" << endl;
    for (int i = 0; i < 3; i++)
    {
        tablicaPunktow[i].skaluj(2);
    }

    // wywołanie funkcji drukuj dla każdego obiektu
    for (int i = 0; i < 3; i++)
    {
        drukuj(tablicaPunktow[i]);
    }
    cout << endl;

    // wywołanie metody statycznej getLicznik
    cout << "Liczba obiektow: " << Punkt::getLicznik() << endl;
    cout << "______________________________________________________" << endl;
    cout << "Koniec czesci drugiej" << endl
         << endl;
}

// funckcja wywołująca metodę pokaz dla każdego obiektu typu kontobankowe
void pokazKonta(KontoBankowe *tablica[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Konto " << i + 1 << ": ";
        tablica[i]->pokaz();
        cout << endl;
    }
}

// funkcja zewnętrzna do klasy Punkt - wyświetla opis punktu i jego składowe
void drukuj(Punkt p)
{
    cout << "Punkt: (" << p.odcieta() << ", " << p.rzedna() << ")" << endl;
}

// funkcja zewnętrzna do klasy Punkt która sprawdza czy dwa punkty są w takiej samej odległości od początku układu współrzędnych
bool czyOdleglosc(Punkt p1, Punkt p2)
{
    int przekatna = sqrt(pow(p1.odcieta(), 2) + pow(p1.rzedna(), 2));
    int przekatna2 = sqrt(pow(p2.odcieta(), 2) + pow(p2.rzedna(), 2));
    if (przekatna == przekatna2)
    {
        return true;
    }
    else
    {
        return false;
    }
}