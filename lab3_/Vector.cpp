#include "Vector.h"

// iniclaizacja statycznej zmiennej counter
int Vector::counter = 0;

// inicjalizacja konstruktora bezargumentowego klasy vector
Vector::Vector()
{
    n = 0;
    array = nullptr;
    counter++;
}

/*Konstruktor o jednym całkowitym argumencie, który określa liczbę elementów tablicy array, czyli
polu n przypisuje wartość argumentu, a przy pomocy wskaźnika array tworzy dynamiczną tablicę
n-elementową i każdemu jej elementowi przypisuje wartość 0.*/
Vector::Vector(int n)
{
    this->n = n;
    array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
    }
    counter++;
}

/* inicjalizacja konstruktora klasy vector. Konstruktor o dwu całkowitych argumentach, który polu n przypisuje wartość pierwszego argumentu,
przy pomocy wskaźnika array tworzy dynamiczną tablicę n-elementową i każdemu jej elementowi przypisuje wartość drugiego argumentu.*/
Vector::Vector(int n, int h)
{
    this->n = n;
    array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = h;
    }
    counter++;
}

// inicjalizacja konstruktora kopiującego klasy vector
Vector::Vector(const Vector &v)
{
    n = v.n;
    array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = v.array[i];
    }
    counter++;
}

// incicjalizacja destruktora klasy vector
Vector::~Vector()
{
    delete[] array;
    counter--;
}

// inicjalizacja opreratora przypisania klasy vector
Vector &Vector::operator=(const Vector &v)
{
    if (this == &v)
    {
        return *this;
    }
    delete[] array;
    n = v.n;
    array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = v.array[i];
    }
    return *this;
}

// inicjalizacja metody Print() klasy vector
void Vector::Print()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// inciializacja metody Change() klasy vector
void Vector::Change(int j, int new_value)
{
    array[j] = new_value;
}

// incicjalizacja metody Return() klasy vector
int Vector::Return(int j)
{
    return array[j];
}

// inciializacja funkcji Sum() klasy vector
Vector Sum(const Vector &w1, const Vector &w2)
{
    Vector result;
    if (w1.n > w2.n)
    {
        result = Vector(w1);
        for (int i = 0; i < w2.n; i++)
        {
            result.array[i] = w1.array[i] + w2.array[i];
        }
    }
    else
    {
        result = Vector(w2);
        for (int i = 0; i < w1.n; i++)
        {
            result.array[i] = w1.array[i] + w2.array[i];
        }
    }
    return result;
}

// inicjalizacja metody GetCounter() klasy vector
int Vector::GetCounter()
{
    return counter;
}

// inicjalizacja przeciążenia operatora +
Vector Vector::operator+(const Vector &v)
{
    Vector result;
    if (n > v.n)
    {
        result = Vector(*this);
        for (int i = 0; i < v.n; i++)
        {
            result.array[i] = array[i] + v.array[i];
        }
    }
    else
    {
        result = Vector(v);
        for (int i = 0; i < n; i++)
        {
            result.array[i] = array[i] + v.array[i];
        }
    }
    return result;
}

// inicjalizacja przeciążenia operatora -
Vector Vector::operator-(const Vector &v)
{
    Vector result;
    if (n > v.n)
    {
        result = Vector(*this);
        for (int i = 0; i < v.n; i++)
        {
            result.array[i] = array[i] - v.array[i];
        }
    }
    else
    {
        result = Vector(v);
        for (int i = 0; i < n; i++)
        {
            result.array[i] = array[i] - v.array[i];
        }
    }
    return result;
}

// inicjalizacja przeciążenia operatora *
Vector Vector::operator*(const Vector &v)
{
    Vector result;
    if (n > v.n)
    {
        result = Vector(*this);
        for (int i = 0; i < v.n; i++)
        {
            result.array[i] = array[i] * v.array[i];
        }
    }
    else
    {
        result = Vector(v);
        for (int i = 0; i < n; i++)
        {
            result.array[i] = array[i] * v.array[i];
        }
    }
    return result;
}

// inicjalizacja przeciążenia operatora /
Vector Vector::operator/(const Vector &v)
{
    Vector result;
    if (n > v.n)
    {
        result = Vector(*this);
        for (int i = 0; i < v.n; i++)
        {
            result.array[i] = array[i] / v.array[i];
        }
    }
    else
    {
        result = Vector(v);
        for (int i = 0; i < n; i++)
        {
            result.array[i] = array[i] / v.array[i];
        }
    }
    return result;
}

// inicjalizacja przeciążenia operatora +=
Vector &Vector::operator+=(const Vector &v)
{
    if (n > v.n)
    {
        for (int i = 0; i < v.n; i++)
        {
            array[i] += v.array[i];
        }
    }
    else
    {
        Vector result = Vector(v);
        for (int i = 0; i < n; i++)
        {
            result.array[i] = array[i] + v.array[i];
        }
        *this = result;
    }
    return *this;
}

// inicjalizacja przeciążenia operatora -=
Vector &Vector::operator-=(const Vector &v)
{
    if (n > v.n)
    {
        for (int i = 0; i < v.n; i++)
        {
            array[i] -= v.array[i];
        }
    }
    else
    {
        Vector result = Vector(v);
        for (int i = 0; i < n; i++)
        {
            result.array[i] = array[i] - v.array[i];
        }
        *this = result;
    }
    return *this;
}

// inicjalizacja przeciążenia operatora *=
Vector &Vector::operator*=(const Vector &v)
{
    if (n > v.n)
    {
        for (int i = 0; i < v.n; i++)
        {
            array[i] *= v.array[i];
        }
    }
    else
    {
        Vector result = Vector(v);
        for (int i = 0; i < n; i++)
        {
            result.array[i] = array[i] * v.array[i];
        }
        *this = result;
    }
    return *this;
}

// inicjalizacja przeciążenia operatora /=
Vector &Vector::operator/=(const Vector &v)
{
    if (n > v.n)
    {
        for (int i = 0; i < v.n; i++)
        {
            array[i] /= v.array[i];
        }
    }
    else
    {
        Vector result = Vector(v);
        for (int i = 0; i < n; i++)
        {
            result.array[i] = array[i] / v.array[i];
        }
        *this = result;
    }
    return *this;
}

// inicjalizacja przeciążenia operatora ==
bool Vector::operator==(const Vector &v)
{
    if (n != v.n)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] != v.array[i])
            {
                return false;
            }
        }
    }
    return true;
}

// inicjalizacja przeciążenia operatora !=
bool Vector::operator!=(const Vector &v)
{
    if (n != v.n)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] != v.array[i])
            {
                return true;
            }
        }
    }
    return false;
}

// inicjalizacja przeciążenia operatora <
bool Vector::operator<(const Vector &v)
{
    if (n < v.n)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] < v.array[i])
            {
                return true;
            }
        }
    }
    return false;
}

// inicjalizacja przeciążenia operatora >
bool Vector::operator>(const Vector &v)
{
    if (n > v.n)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] > v.array[i])
            {
                return true;
            }
        }
    }
    return false;
}

// inicjalizacja przeciążenia operatora <=
bool Vector::operator<=(const Vector &v)
{
    if (n < v.n)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] <= v.array[i])
            {
                return true;
            }
        }
    }
    return false;
}

// inicjalizacja przeciążenia operatora >=
bool Vector::operator>=(const Vector &v)
{
    if (n > v.n)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] >= v.array[i])
            {
                return true;
            }
        }
    }
    return false;
}

// inicjalizacja przeciążenia operatora []
int &Vector::operator[](int i)
{
    return array[i];
}

// inicjalizacja przeciążenia operatora <<
std::ostream &operator<<(std::ostream &out, const Vector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        out << v.array[i] << " ";
    }
    return out;
}

// inicjalizacja przeciążenia operatora >>
std::istream &operator>>(std::istream &in, Vector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        in >> v.array[i];
    }
    return in;
}

// inicjalizacja przeciążenia operatora +
Vector operator+(const Vector &v1, const Vector &v2)
{
    Vector result = Vector(v1);
    result += v2;
    return result;
}

// inicjalizacja przeciążenia operatora -
Vector operator-(const Vector &v1, const Vector &v2)
{
    Vector result = Vector(v1);
    result -= v2;
    return result;
}

// inicjalizacja przeciążenia operatora *
Vector operator*(const Vector &v1, const Vector &v2)
{
    Vector result = Vector(v1);
    result *= v2;
    return result;
}

// inicjalizacja przeciążenia operatora /
Vector operator/(const Vector &v1, const Vector &v2)
{
    Vector result = Vector(v1);
    result /= v2;
    return result;
}

// inicjalizacja przeciążenia operatora *
Vector operator*(const Vector &v, int n)
{
    Vector result = Vector(v);
    result *= n;
    return result;
}

// inicjalizacja przeciążenia operatora ++
Vector &Vector::operator++()
{
    for (int i = 0; i < n; i++)
    {
        array[i]++;
    }
    return *this;
}

// inicjalizacja przeciążenia operatora --
Vector &Vector::operator--()
{
    for (int i = 0; i < n; i++)
    {
        array[i]--;
    }
    return *this;
}

// inicjalizacja przeciążenia operatora ++
Vector Vector::operator++(int)
{
    Vector result = Vector(*this);
    for (int i = 0; i < n; i++)
    {
        array[i]++;
    }
    return result;
}

// inicjalizacja przeciążenia operatora --
Vector Vector::operator--(int)
{
    Vector result = Vector(*this);
    for (int i = 0; i < n; i++)
    {
        array[i]--;
    }
    return result;
}
