#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr1(n);
    vector <int> arr2(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    string s;
    cin.ignore();
    getline(cin, s);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == ' ')
        {
            arr2[i] = 0;
        }
        else if('A' <= s[i] && s[i] <= 'Z')
        {
            arr2[i] = s[i] - 'A' + 1;
        }
        else
        {
            arr2[i] = s[i] - 'a' + 27;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for(int i = 0; i < n; i++)
    {
        if(arr1[i] != arr2[i])
        {
            cout << "n\n";
            return 0;
        }
    }

    cout << "y\n";
}