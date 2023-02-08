// szablon funkcji sortującej tablicę
#ifndef SZABLON_H
#define SZABLON_H
#include <iostream>
using namespace std;

template <class T>
void sortuj(T tab[], int n)
{
  T temp;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (tab[i] > tab[j])
      {
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
      }
}

// szablon funkcji wypisującej elementy tablicy
template <class T>
void wypisz(T tab[], int n)
{
  for (int i = 0; i < n; i++)
    cout << tab[i] << " ";
  cout << endl;
}

// szablon funkcji zwracającej indeks elementu o największej wartości
template <class T>
int max(T tab[], int n)
{
  int max = 0;
  for (int i = 1; i < n; i++)
    if (tab[i] > tab[max])
      max = i;
  return max;
}

// szablon funkcji zwracającej indeks elementu o najmniejszej wartości
template <class T>
int min(T tab[], int n)
{
  int min = 0;
  for (int i = 1; i < n; i++)
    if (tab[i] < tab[min])
      min = i;
  return min;
}

#endif