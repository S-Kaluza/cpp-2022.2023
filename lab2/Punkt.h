#ifndef PUNKT_H
#define PUNKT_H

using namespace std;

class Punkt
{
private:
    char nazwa;
    double x, y;
    static int licznik;

public:
    Punkt();
    Punkt(double, double);
    Punkt(char, double, double);
    Punkt(const Punkt &);
    ~Punkt();
    Punkt operator=(Punkt);
    Punkt operator+(Punkt);
    void przesun(double, double);
    void skaluj(double);
    double odcieta();
    double rzedna();
    static int getLicznik();
};
#endif