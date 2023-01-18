#include "Ulamek.h"

using std::cout;
using std::endl;

Ulamek::Ulamek(int licznik, int mianownik)
{
    int q = nwd((licznik < 0) ? -licznik : licznik, (mianownik < 0) ? -mianownik : mianownik);
    this->licznik = (mianownik < 0) ? -licznik / q : licznik / q;
    this->mianownik = (mianownik < 0) ? -mianownik / q : mianownik / q;
}

int Ulamek::nwd(int p, int q)
{
    if (q == 0)
        return p;
    return nwd(q, p % q);
}

Ulamek::Ulamek(const Ulamek &u)
{
    licznik = u.licznik;
    mianownik = u.mianownik;
}

// destruktor
Ulamek::~Ulamek()
{
    cout << "destruktor" << endl;
}

// zwroc licznik
int Ulamek::ZwrocLicznik() const
{
    return licznik;
}

// zwroc mianownik
int Ulamek::ZwrocMianownik() const
{
    return mianownik;
}

// dodaj ulamki
void Ulamek::dodajUlamki(Ulamek u1, Ulamek u2)
{
    licznik = u1.licznik * u2.mianownik + u2.licznik * u1.mianownik;
    mianownik = u1.mianownik * u2.mianownik;
}

// operator =
Ulamek &Ulamek::operator=(const Ulamek &u)
{
    licznik = u.licznik;
    mianownik = u.mianownik;
    return *this;
}

// operator +
Ulamek Ulamek::operator+(const Ulamek &u)
{
    Ulamek temp;
    temp.licznik = licznik * u.mianownik + u.licznik * mianownik;
    temp.mianownik = mianownik * u.mianownik;
    return temp;
}

// operator -
Ulamek Ulamek::operator-(const Ulamek &u)
{
    Ulamek temp;
    temp.licznik = licznik * u.mianownik - u.licznik * mianownik;
    temp.mianownik = mianownik * u.mianownik;
    return temp;
}

// operator *
Ulamek Ulamek::operator*(const Ulamek &u)
{
    Ulamek temp;
    temp.licznik = licznik * u.licznik;
    temp.mianownik = mianownik * u.mianownik;
    return temp;
}

// operator /
Ulamek Ulamek::operator/(const Ulamek &u)
{
    Ulamek temp;
    temp.licznik = licznik * u.mianownik;
    temp.mianownik = mianownik * u.licznik;
    return temp;
}

// operator +=
Ulamek &Ulamek::operator+=(const Ulamek &u)
{
    licznik = licznik * u.mianownik + u.licznik * mianownik;
    mianownik = mianownik * u.mianownik;
    return *this;
}

// operator -=
Ulamek &Ulamek::operator-=(const Ulamek &u)
{
    licznik = licznik * u.mianownik - u.licznik * mianownik;
    mianownik = mianownik * u.mianownik;
    return *this;
}

// operator *=
Ulamek &Ulamek::operator*=(const Ulamek &u)
{
    licznik = licznik * u.licznik;
    mianownik = mianownik * u.mianownik;
    return *this;
}

// operator /=
Ulamek &Ulamek::operator/=(const Ulamek &u)
{
    licznik = licznik * u.mianownik;
    mianownik = mianownik * u.licznik;
    return *this;
}

// operator ==
bool Ulamek::operator==(const Ulamek &u)
{
    return licznik * u.mianownik == u.licznik * mianownik;
}

// operator !=
bool Ulamek::operator!=(const Ulamek &u)
{
    return licznik * u.mianownik != u.licznik * mianownik;
}

// operator >
bool Ulamek::operator>(const Ulamek &u)
{
    return licznik * u.mianownik > u.licznik * mianownik;
}

// operator <
bool Ulamek::operator<(const Ulamek &u)
{
    return licznik * u.mianownik < u.licznik * mianownik;
}

// operator >=
bool Ulamek::operator>=(const Ulamek &u)
{
    return licznik * u.mianownik >= u.licznik * mianownik;
}

// operator <=
bool Ulamek::operator<=(const Ulamek &u)
{
    return licznik * u.mianownik <= u.licznik * mianownik;
}

// operator <<
std::ostream &operator<<(std::ostream &out, const Ulamek &u)
{
    out << u.licznik << "/" << u.mianownik;
    return out;
}

// operator >>
std::istream &operator>>(std::istream &in, Ulamek &u)
{
    in >> u.licznik >> u.mianownik;
    return in;
}

// operator ++
Ulamek &Ulamek::operator++()
{
    licznik += mianownik;
    return *this;
}

// operator ++
Ulamek Ulamek::operator++(int)
{
    Ulamek temp = *this;
    licznik += mianownik;
    return temp;
}

// operator --
Ulamek &Ulamek::operator--()
{
    licznik -= mianownik;
    return *this;
}

// operator --

Ulamek Ulamek::operator--(int)
{
    Ulamek temp = *this;
    licznik -= mianownik;
    return temp;
}