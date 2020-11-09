// έξοδος 5 τυχαίων τιμών στο διάστημα [0,V)
// χρήση συναρτήσεων της C++

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    int V = 543;
    mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, V);
    for (int i = 0; i < 5; i++)
        cout << dist(generator) << " ";
}

/*
430 206 272 514 180 
*/