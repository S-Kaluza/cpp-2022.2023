#include <iostream>
#include "Vector.h"
#include "Ulamek.h"

using std::cout;
using std::endl;

int main()
{
    // obiekty klasy vector
    Vector v1;
    Vector v2(5);
    Vector v3(5, 3);
    Vector v4(v3);

    // wyświetlenie obiektów klasy vector
    cout << "v1: ";
    v1.Print();
    cout << "v2: ";
    v2.Print();
    cout << "v3: ";
    v3.Print();
    cout << "v4: ";
    v4.Print();

    // zmiana wartości elementu tablicy obiektu v3
    v3.Change(2, 5);

    cout << "po zmianie w tablicy v3 elementu o indexie 2 na liczbę 5" << endl;
    // wyświetlenie obiektów klasy vector
    cout << "v1: ";
    v1.Print();
    cout << "v2: ";
    v2.Print();
    cout << "v3: ";
    v3.Print();
    cout << "v4: ";
    v4.Print();

    // przypisanie obiektu v3 do v1
    v1 = v3;

    // wyświetlenie obiektów klasy vector
    cout << "po przypisaniu v3 do v1" << endl;
    cout << "v1: ";
    v1.Print();
    cout << "v2: ";
    v2.Print();
    cout << "v3: ";
    v3.Print();
    cout << "v4: ";
    v4.Print();

    // sumowanie zawartości obiektów v1 i v2
    Vector v5 = Sum(v1, v3);
    cout << "po sumowaniu v1 i v3 wartosc wektora wynosi: ";
    // wyświetlenie vector v5
    v5.Print();

    // wyświetlenie elementu tablicy obiektu v5 o indeksie 2
    cout << "v5[2] = " << v5.Return(2) << endl;

    // wyświetlenie ilości utworzonych obiektów klasy vector
    cout << "ilosc elementow klasy vector: " << Vector::GetCounter() << endl;

    // usunięcie obiektów klasy vector
    v1.~Vector();
    v2.~Vector();

    // wyświetlenie ilości utworzonych obiektów klasy vector
    cout << "ilosc elementow klasy vector po usunieciu 2 z nich: " << Vector::GetCounter() << endl;

    // utworzenie obiektu klasy vector
    Vector v6(5, 2);

    // wyświetlenie ilości utworzonych obiektów klasy vector
    cout << "ilosc elementow klasy vector po utworzeniu 1 nowego: " << Vector::GetCounter() << endl;

    // deklaracja tablicy 10 elementów klasy vector
    Vector tab[10];

    // deklaracja obiektów klasy vector znajdujących się w tablicy tab
    for (int i = 0; i < 10; i++)
    {
        tab[i] = Vector(i + 1, i + 1);
    }

    cout << "tab[7]: ";
    // wyświetlenie obiektu o indeksie 7 z tablicy tab
    tab[7].Print();

    // wyświetlenie 3 elementu obiektu vector, znajdującego się w tablicy tab na indeksie 7
    cout << "tab[7][3] = " << tab[7].Return(3) << endl;

    // zmiana 3 elementu obiektu vector na liczbę 10, znajdującego się w tablicy tab na indeksie 7
    cout << "po zmianie 3 elementu tab[7] na 10" << endl;
    cout << "tab[7]: ";
    tab[7].Change(3, 10);
    tab[7].Print();

    // wyświetlenie ilości utworzonych obiektów klasy vector
    cout << "ilosc elementow klasy vector: " << Vector::GetCounter() << endl;

    // Utwórz dynamicznie obiekt klasy Vector i na jego rzecz wywołaj dostępne metody
    Vector *v7 = new Vector(5, 2);
    cout << "v7: ";
    v7->Print();
    cout << "v7[2] = " << v7->Return(2) << endl;
    cout << "po zmianie elementu obiektu v7 o indeksie 2 na 10" << endl;
    v7->Change(2, 10);
    cout << "v7: ";
    v7->Print();
    cout << "ilosc elementow klasy vector: " << Vector::GetCounter() << endl;
    delete v7;
    // testowanie pozostałych metod klassy Vector
    Vector vTest = Vector(5, 7);
    Vector vTest2 = Vector(7, 12);
    cout << "vTest: ";
    vTest.Print();
    cout << "vTest2: ";
    vTest2.Print();
    cout << "vTest + vTest2: ";
    (vTest + vTest2).Print();
    cout << "vTest - vTest2: ";
    (vTest - vTest2).Print();
    cout << "vTest * vTest2: ";
    (vTest * vTest2).Print();
    cout << "vTest / vTest2: ";
    (vTest / vTest2).Print();
    cout << "vTest += vTest2: ";
    (vTest += vTest2).Print();
    cout << "vTest -= vTest2: ";
    (vTest -= vTest2).Print();
    cout << "vTest *= vTest2: ";
    (vTest *= vTest2).Print();
    cout << "vTest /= vTest2: ";
    (vTest /= vTest2).Print();
    cout << "vTest == vTest2: " << (vTest == vTest2) << endl;
    cout << "vTest != vTest2: " << (vTest != vTest2) << endl;
    cout << "vTest > vTest2: " << (vTest > vTest2) << endl;
    cout << "vTest < vTest2: " << (vTest < vTest2) << endl;
    cout << "vTest >= vTest2: " << (vTest >= vTest2) << endl;
    cout << "vTest <= vTest2: " << (vTest <= vTest2) << endl;
    cout << "vTest++: ";
    (vTest++).Print();
    cout << "vTest: ";
    vTest.Print();
    cout << "++vTest: ";
    (++vTest).Print();
    cout << "vTest: ";
    vTest.Print();
    cout << "vTest--: " << vTest-- << endl;
    cout << "vTest: ";
    vTest.Print();
    cout << "--vTest: " << --vTest << endl;
    // test klasy ułamek
    Ulamek u1 = Ulamek(1, 2);
    Ulamek u2 = Ulamek(1, 3);
    cout << "u1: " << u1 << endl;
    cout << "u2: " << u2 << endl;
    cout << "u1 + u2: " << u1 + u2 << endl;
    cout << "u1 - u2: " << u1 - u2 << endl;
    cout << "u1 * u2: " << u1 * u2 << endl;
    cout << "u1 / u2: " << u1 / u2 << endl;
    cout << "u1 += u2: " << (u1 += u2) << endl;
    cout << "u1 -= u2: " << (u1 -= u2) << endl;
    cout << "u1 *= u2: " << (u1 *= u2) << endl;
    cout << "u1 /= u2: " << (u1 /= u2) << endl;
    cout << "u1 == u2: " << (u1 == u2) << endl;
    cout << "u1 != u2: " << (u1 != u2) << endl;
    cout << "u1 > u2: " << (u1 > u2) << endl;
    cout << "u1 < u2: " << (u1 < u2) << endl;
    cout << "u1 >= u2: " << (u1 >= u2) << endl;
    cout << "u1 <= u2: " << (u1 <= u2) << endl;
    cout << "u1++: " << u1++ << endl;
    cout << "++u1: " << ++u1 << endl;
    cout << "u1--: " << u1-- << endl;
    cout << "--u1: " << --u1 << endl;
    return 0;
}