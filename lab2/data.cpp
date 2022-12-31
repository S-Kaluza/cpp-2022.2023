#include <iostream>
using namespace std;

// stała zawierająca kolejne liczby dni w miesiącach
const int dniWMiesiacach[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// stała zawierająca indeksy dni w których zaczyna sie kolejny miesiąc
const int indeksyDniWMiesiacach[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

// stała zawierająca nazwy kolejnych miesiecy
const char *miesiace[12] = {"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "październik", "listopad", "grudzien"};

struct DATA
{
    int dzien;
    int miesiac;
    int rok;
};

bool czyPoprawna(const DATA &data);

// funkcja zwracająca ilosć dni pomiedzy dwoma datami
int DniPomiedzy(const DATA &data1, const DATA &data2)
{
    int iloscDni = 0;
    if (czyPoprawna(data1) && czyPoprawna(data2))
    {
        if (data1.rok == data2.rok)
        {
            if (data1.miesiac == data2.miesiac)
            {
                iloscDni = data2.dzien - data1.dzien;
            }
            else
            {
                iloscDni = 31 - data1.dzien;
                for (int i = data1.miesiac + 1; i < data2.miesiac; i++)
                {
                    iloscDni += 31;
                }
                iloscDni += data2.dzien;
            }
        }
        else
        {
            iloscDni = 31 - data1.dzien;
            for (int i = data1.miesiac + 1; i < 12; i++)
            {
                iloscDni += 31;
            }
            for (int i = 0; i < data2.miesiac; i++)
            {
                iloscDni += 31;
            }
            iloscDni += data2.dzien;
        }
    }
    return iloscDni;
}

// funkcja zwracająca true w przypadku gdy data podana jako pierwszy argument jest wczesniejsza
bool Wczesniejsza(const DATA &data1, const DATA &data2)
{
    if (czyPoprawna(data1) && czyPoprawna(data2))
    {
        if (data1.rok < data2.rok)
        {
            return true;
        }
        else if (data1.rok == data2.rok)
        {
            if (data1.miesiac < data2.miesiac)
            {
                return true;
            }
            else if (data1.miesiac == data2.miesiac)
            {
                if (data1.dzien < data2.dzien)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// funkcja dodająca dni do daty
DATA DodajDni(const DATA &data, int iloscDni)
{
    DATA nowaData = data;
    if (czyPoprawna(data))
    {
        for (int i = 0; i < iloscDni; i++)
        {
            nowaData.dzien++;
            if (nowaData.dzien > 31)
            {
                nowaData.dzien = 1;
                nowaData.miesiac++;
                if (nowaData.miesiac > 12)
                {
                    nowaData.miesiac = 1;
                    nowaData.rok++;
                }
            }
        }
    }
    return nowaData;
}

// funckcja sprawdzająca czy rok jest przestepny
bool RokPrzestepny(int rok)
{
    if (rok >= 1900 && rok <= 2100)
    {
        if (rok % 4 == 0)
        {
            if (rok % 100 == 0)
            {
                if (rok % 400 == 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// funkcja zwracająca liczbe dni od roku 1900
int DniOd1900(const DATA &data)
{
    int iloscDni = 0;
    if (czyPoprawna(data))
    {
        for (int i = 1900; i < data.rok; i++)
        {
            if (RokPrzestepny(i))
            {
                iloscDni += 366;
            }
            else
            {
                iloscDni += 365;
            }
        }
        if (RokPrzestepny(data.rok))
        {
            iloscDni += indeksyDniWMiesiacach[data.miesiac - 1] + data.dzien;
        }
        else
        {
            iloscDni += indeksyDniWMiesiacach[data.miesiac - 1] + data.dzien - 1;
        }
    }
    else
        return -1;
}

// sprawdza czy data jest z zakresu 1 styczeń 1990- 31 grudzień 2100
bool czyPoprawna(const DATA &data)
{
    if (data.rok < 1990 || data.rok > 2100)
        return false;
    if (data.miesiac < 1 || data.miesiac > 12)
        return false;
    if (data.dzien < 1 || data.dzien > dniWMiesiacach[data.miesiac - 1])
        return false;
    if (data.rok == 2100 && data.miesiac == 12 && data.dzien > 31)
        return false;
    if (data.rok == 1990 && data.miesiac == 1 && data.dzien < 1)
        return false;
    return true;
}

// funkcja main - program testujący
int main()
{
    DATA data1 = {20, 2, 2023};
    DATA data2 = {31, 12, 2022};
    DATA data3 = {31, 1845, 12};
    DATA data4 = {29, 2020, 2};
    cout << "czy poprawna test" << endl;
    cout << "Czy data1 jest poprawna? " << czyPoprawna(data1) << endl;
    cout << "Czy data2 jest poprawna? " << czyPoprawna(data2) << endl;
    cout << "Czy data3 jest poprawna? " << czyPoprawna(data3) << endl;
    cout << "Czy data4 jest poprawna? " << czyPoprawna(data4) << endl
         << endl;
    cout << "Wczesniejsza test" << endl;
    cout << "Czy data1 jest wczesniejsza od data2? " << Wczesniejsza(data1, data2) << endl;
    cout << "Czy data2 jest wczesniejsza od data1? " << Wczesniejsza(data2, data1) << endl;
    cout << "Czy data2 jest wczesniejsza od data3? " << Wczesniejsza(data2, data3) << endl;
    cout << "Czy data3 jest wczesniejsza od data4? " << Wczesniejsza(data3, data4) << endl;
    cout << "dni pomiedzy test" << endl;
    cout << "Ile dni jest pomiedzy data1 a data2? " << DniPomiedzy(data1, data2) << endl;
    cout << "Ile dni jest pomiedzy data2 a data3? " << DniPomiedzy(data2, data3) << endl;
    cout << "Ile dni jest pomiedzy data3 a data4? " << DniPomiedzy(data3, data4) << endl;
    cout << "Dni od 1900 test" << endl;
    cout << "Ile dni upłyneło od 1900 do data1? " << DniOd1900(data1) << endl;
    cout << "Ile dni upłyneło od 1900 do data2? " << DniOd1900(data2) << endl;
    cout << "Ile dni upłyneło od 1900 do data3? " << DniOd1900(data3) << endl;
    cout << "Ile dni upłyneło od 1900 do data4? " << DniOd1900(data4) << endl;
    cout << "Rok przestepny test" << endl;
    cout << "Czy rok 2020 jest przestepny? " << RokPrzestepny(2020) << endl;
    cout << "Czy rok 2021 jest przestepny? " << RokPrzestepny(2021) << endl;
    cout << "Czy rok 2022 jest przestepny? " << RokPrzestepny(2022) << endl;
    cout << "Czy rok 2023 jest przestepny? " << RokPrzestepny(2023) << endl;
    cout << "Czy rok 2024 jest przestepny? " << RokPrzestepny(2024) << endl;
    cout << "dodaj dni test" << endl;
    cout << "Dodaj 1 dzień do data1: " << endl;
    cout << "Dzień pierwotny: " << data1.dzien << endl;
    cout << "Dzień po modyfikacji: " << DodajDni(data1, 1).dzien << endl;

    return 0;
}
