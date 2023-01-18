#ifndef ULAMEK_H
#define ULAMEK_H
#include <iostream>

class Ulamek
{
private:
    int licznik;
    int mianownik;
    int nwd(int p, int q);

public:
    Ulamek(int licznik = 0, int mianownik = 1);
    Ulamek(const Ulamek &u);
    ~Ulamek();
    int ZwrocLicznik() const;
    int ZwrocMianownik() const;
    void dodajUlamki(Ulamek, Ulamek);
    Ulamek &operator=(const Ulamek &u);
    Ulamek operator+(const Ulamek &u);
    Ulamek operator/(const Ulamek &u);
    Ulamek operator-(const Ulamek &u);
    Ulamek operator*(const Ulamek &u);
    Ulamek &operator+=(const Ulamek &u);
    Ulamek &operator/=(const Ulamek &u);
    Ulamek &operator-=(const Ulamek &u);
    Ulamek &operator*=(const Ulamek &u);
    bool operator==(const Ulamek &u);
    bool operator!=(const Ulamek &u);
    bool operator<(const Ulamek &u);
    bool operator>(const Ulamek &u);
    bool operator<=(const Ulamek &u);
    bool operator>=(const Ulamek &u);
    Ulamek &operator++();
    Ulamek operator++(int);
    Ulamek &operator--();
    Ulamek operator--(int);
    friend std::ostream &operator<<(std::ostream &out, const Ulamek &u);
    friend std::istream &operator>>(std::istream &in, Ulamek &u);
};

#endif