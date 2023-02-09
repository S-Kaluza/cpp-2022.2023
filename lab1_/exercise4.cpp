#include<iostream>
#include<cmath>

using std::cout;
using std::cin;
using std::pow;

const float GRAVITY_CONSTANT = 9.8;

double distanceFallen(int x_second){
    return (GRAVITY_CONSTANT * (x_second * x_second))/2;
}

int exercise4(){
    int distance;
    int second;
    cout << "Podaj dystans do gleby";
    cin >> distance;
    for(int i = 0; distanceFallen(i) < distance ; i++){
        cout << "w " << i << " sekundzie piłka jest na wysokości: " << distance - distanceFallen(i) << std::endl;
        second = i;
    }
    cout << "piłka jest na ziemi po " << second + 1 << " sekundach";
}