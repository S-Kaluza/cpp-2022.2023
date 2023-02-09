#include<iostream>

const int GLOBAL=5;

using std::cout;

int exercise6(){
    const int local = 10;
    cout <<  GLOBAL << std::endl << local;
}