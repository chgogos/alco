// έξοδος 5 τυχαίων τιμών στο διάστημα [0,V)
// χρήση της srand() και rand() της C

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    int V = 543;
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
        cout << rand() % V + 1 << " ";
}

/*
169 30 383 408 221 
*/