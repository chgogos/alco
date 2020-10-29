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
