#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> vec = {0, 1, 2, 3, 4};

    do
    {
        for(int i = 0; i < 5; i++)
        {
            cout << vec[i];
        }
        cout << endl;
    }
    while(next_permutation(vec.begin(), vec.end()));
}