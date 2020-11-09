// καταμέτρηση των κοινών στοιχείων ανάμεσα σε 2 vectors
// O(n^2)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a{1, 2, 3, 4, 5}, b{3, 4, 5, 6, 7};
    int c = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                c++;
                break;
            }
        }
    }
    cout << "Number of common elements: " << c << endl;
}

/*
Number of common elements: 3 
*/