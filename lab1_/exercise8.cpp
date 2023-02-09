#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;

int exercise8() {
    string name;
    string surname;
    int age;
    cout << "podaj imię i nazwisko";
    cin >> name >> surname;
    cout << "podaj wiek";
    cin >> age;
    cout << "twój wiek plus długość imienia i nazwiska to: " << name.length() + surname.length() + age;
}