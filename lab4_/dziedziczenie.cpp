#ifndef PERSONEL_H
#define PERSONEL_H
#include <iostream>

using namespace std;

class Personel
{
private:
    string nazwisko;
    int biuro;

public:
    Personel(string nazwisko, int biuro)
    {
        this->nazwisko = nazwisko;
        this->biuro = biuro;
    }

    virtual ~Personel()
    {
        cout << "Personel destructor" << endl;
    };

    virtual void wypisz() const
    {
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Biuro: " << biuro << endl;
    };

    void przydziel_biuro(int numer)
    {
        biuro = numer;
    };

    string telefon() const
    {
        return to_string(this->biuro);
    };
};

class Pracownik : public Personel
{
private:
    float stawka;
    float godziny;

public:
    Pracownik(string nazwisko, int biuro, float stawka, float godziny) : Personel(nazwisko, biuro)
    {
        this->stawka = stawka;
        this->godziny = godziny;
    }
    virtual ~Pracownik()
    {
        cout << "Pracownik destructor" << endl;
    }

    void ustaw_stawke(float stawka)
    {
        this->stawka = stawka;
    };

    void ustaw_godziny(float godziny)
    {
        this->godziny = godziny;
    };

    float oblicz_place()
    {
        return stawka * godziny;
    };

    void wypisz() const
    {
        cout << "Pracownik" << endl;
        Personel::wypisz();
        cout << "Stawka: " << stawka << endl;
        cout << "Godziny: " << godziny << endl;
    };
};

class Sprzedawca : public Pracownik
{
private:
    float procent;
    float sprzedaz;

public:
    Sprzedawca(string nazwisko, int biuro, float stawka, float godziny, float procent, float sprzedaz) : Pracownik(nazwisko, biuro, stawka, godziny)
    {
        this->procent = procent;
        this->sprzedaz = sprzedaz;
    }
    virtual ~Sprzedawca()
    {
        cout << "Sprzedawca destructor" << endl;
    }

    void ustaw_procent(float procent)
    {
        this->procent = procent;
    };

    void ustaw_sprzedaz(float sprzedaz)
    {
        this->sprzedaz = sprzedaz;
    };

    float oblicz_place()
    {
        return Pracownik::oblicz_place() + sprzedaz * (procent / 100);
    };

    void wypisz() const
    {
        Pracownik::wypisz();
        cout << "Sprzedawca" << endl;
    };
};

class Dyrektor : public Personel
{
private:
    float premia;
    float pensja;
    float ilu_pracownikow;

public:
    Dyrektor(string nazwisko, int biuro, float premia, float pensja, float ilu_pracownikow) : Personel(nazwisko, biuro)
    {
        this->premia = premia;
        this->pensja = pensja;
        this->ilu_pracownikow = ilu_pracownikow;
    }
    virtual ~Dyrektor()
    {
        cout << "Dyrektor destructor" << endl;
    }

    void ustaw_premie(float premia)
    {
        this->premia = premia;
    };

    void ustaw_pensje(float pensja)
    {
        this->pensja = pensja;
    };

    void ustaw_ilu_pracownikow(float ilu_pracownikow)
    {
        this->ilu_pracownikow = ilu_pracownikow;
    };

    float oblicz_place()
    {
        return pensja + premia * ilu_pracownikow;
    };

    void wypisz() const
    {
        cout << "Dyrektor" << endl;
        Personel::wypisz();
        cout << "Premia: " << premia << endl;
        cout << "Pensja: " << pensja << endl;
        cout << "Ilu pracownikow: " << ilu_pracownikow << endl;
    };
};

// klasa dyrektor handlowy dziedziczy po klasie dyrektor i sprzedawca
class DyrektorHandlowy : public Dyrektor, public Sprzedawca
{
public:
    DyrektorHandlowy(const string);
    virtual ~DyrektorHandlowy()
    {
        cout << "DyrektorHandlowy destructor" << endl;
    };
    void wypisz() const
    {
        Dyrektor::wypisz();
        Sprzedawca::wypisz();
        cout << "Dyrektor Handlowy" << endl;
    };
};
#endif