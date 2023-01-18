#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{ // funckcja statyczna umożliwiająca kontrolę ile elementów zostało utworzonych
    static int counter;
    // deklracja zaprzyjaźnionej funkcji Sum(const Vector &w1, const Vector &w2)
    friend Vector Sum(const Vector &w1, const Vector &w2);

private:
    int n;
    int *array;

public:
    // deklaracja kostruktora bezargumentowego
    Vector();
    // deklaracja konstruktora z argumentem
    Vector(int n);
    // deklaracja kostruktora o 2 argumentach
    Vector(int n, int h);
    // deklaracja konstruktora kopiującego
    Vector(const Vector &v);
    // deklaracja destruktora
    ~Vector();
    // deklaracja operatora przypisania
    Vector &operator=(const Vector &v);
    // deklaracja metody Print()
    void Print();
    // deklaracja metody Change()
    void Change(int j, int new_value);
    // deklaracja metody Return(j)
    int Return(int j);
    // deklaracja metody GetCounter()
    static int GetCounter();
    // deklaracja przeciążenia operatora +
    Vector operator+(const Vector &v);
    // deklaracja przeciążenia operatora /
    Vector operator/(const Vector &v);
    // deklaracja przeciążenia operatora -
    Vector operator-(const Vector &v);
    // deklaracja przeciążenia operatora *
    Vector operator*(const Vector &v);
    // deklaracja przeciążenia operatora +=
    Vector &operator+=(const Vector &v);
    // deklaracja przeciążenia operatora /=
    Vector &operator/=(const Vector &v);
    // deklaracja przeciążenia operatora -=
    Vector &operator-=(const Vector &v);
    // deklaracja przeciążenia operatora *=
    Vector &operator*=(const Vector &v);
    // deklaracja przeciążenia operatora ==
    bool operator==(const Vector &v);
    // deklaracja przeciążenia operatora !=
    bool operator!=(const Vector &v);
    // deklaracja przeciążenia operatora <
    bool operator<(const Vector &v);
    // deklaracja przeciążenia operatora >
    bool operator>(const Vector &v);
    // deklaracja przeciążenia operatora <=
    bool operator<=(const Vector &v);
    // deklaracja przeciążenia operatora >=
    bool operator>=(const Vector &v);
    // deklaracja przeciążenia operatora ++
    Vector &operator++();
    Vector operator++(int);
    // deklaracja przeciążenia operatora --
    Vector &operator--();
    Vector operator--(int);
    // deklaracja przeciążenia operatora []
    int &operator[](int i);
    // deklaracja przeciążenia operatora <<
    friend std::ostream &operator<<(std::ostream &out, const Vector &v);
    // deklaracja przeciążenia operatora >>
    friend std::istream &operator>>(std::istream &in, Vector &v);
};
#endif