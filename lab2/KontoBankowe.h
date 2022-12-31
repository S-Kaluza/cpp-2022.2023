#ifndef KONTO_BANKOWE_H
#define KONTO_BANKOWE_H
#include <string>

using namespace std;

class KontoBankowe
{
private:
    string nazwaDepozytariusza;
    string numerKonta;
    double saldo;
    static int licznik;

public:
    KontoBankowe(string nazwaDepozytariusza, string numerKonta, double saldo);
    ~KontoBankowe();
    void setNazwaDepozytariusza(string nazwaDepozytariusza);
    void setNumerKonta(string numerKonta);
    void setSaldo(double saldo);
    void pokaz();
    void wplata(double kwota);
    void wyplata(double kwota);
    KontoBankowe operator+=(double kwota);
    KontoBankowe operator=(KontoBankowe konto);
    static int getLicznik();
};
#endif