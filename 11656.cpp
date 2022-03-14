#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;

    vector <string> arr;

    int n = str.length();

    for(int i = 0; i < n; i++)
    {
        string temp = str.substr(i, n-i);
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}