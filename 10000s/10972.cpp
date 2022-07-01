#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector <int> permutation;
    vector <int> initial_permutation;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        permutation.push_back(temp);
        initial_permutation.push_back(i+1);
    }

    next_permutation(permutation.begin(), permutation.end());

    if(permutation == initial_permutation)
    {
        cout << "-1";
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout << permutation[i] << " ";
        }
    }

}