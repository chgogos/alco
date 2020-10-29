#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    set<int> a{1, 2, 3, 4, 5}, b{3, 4, 5, 6, 7};

    vector<int> common;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(common));

    cout << "Common elements (" << common.size() << "): ";
    for (int x : common)
    {
        cout << x << " ";
    }
}

/*
Common elements (3): 3 4 5 
*/