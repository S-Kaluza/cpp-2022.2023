#include <iostream>
#include "Okno.cpp"
using std::endl;

int main()
{
    Okno okno(8, 4);
    okno.rysuj();
    cout << endl;
    OknoZRamka oknoZRamka(8, 4, 3);
    oknoZRamka.rysuj();
    cout << endl;
    OknoZMenu oknoZMenu(8, 3, 4);
    oknoZMenu.rysuj();
    cout << endl;
    OknoZMenuZRamka oknoZMenuZRamka(8, 5, 4, "Menu");
    oknoZMenuZRamka.rysuj();
    delete &okno;
    return 0;
}