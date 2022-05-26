#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector <string> names;
    vector <string> increase_sorted_names;
    vector <string> decrease_sorted_names;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        names.push_back(str);
    }

    increase_sorted_names = names;
    decrease_sorted_names = names;

    sort(increase_sorted_names.begin(), increase_sorted_names.end());
    
    for(int i = 0; i < n; i++)
    {
        decrease_sorted_names[i] = increase_sorted_names[n-i-1];
    }

    if(names == increase_sorted_names)
    {
        cout << "INCREASING";
    }
    else if(names == decrease_sorted_names)
    {
        cout << "DECREASING";
    }
    else
    {
        cout << "NEITHER";
    }
}