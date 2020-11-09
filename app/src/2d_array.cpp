#include <iostream>

using namespace std;

void print(int **arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print(int *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i * N + j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cout << "Enter dimension N of N x N matrix: ";
    cin >> N;

    // δυναμικός δισδιάστατος πίνακας Ν Χ Ν
    cout << "Dynamic 2D matrix N x N" << endl;
    int **a = new int *[N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    int c = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = ++c;

    print(a, N);

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    // δυναμικός μονοδιάστατος πίνακας Ν * N  στοιχείων που χρησιμοποιείται ως δισδιάστατος πίνακας N X N
    cout << "Dynamic 1D array N * N used as a 2D matrix N x N" << endl;
    int *b = new int[N];
    c = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            b[i * N + j] = ++c;

    print(b, N);

    delete[] b;
}