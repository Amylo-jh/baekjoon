#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    int n;
    cin >> str >> n;
    vector<vector<char>> arr(n);
    for (int i = 0; i < str.length(); i++)
    {
        arr[i % n].push_back(str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }
    for (int i = 0; i < str.length(); i++)
    {
        cout << arr[i % n][i / n];
    }
}