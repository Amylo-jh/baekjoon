#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    if(a.length() != b.length())
    {
        return a.length() < b.length();
    }

    int anum = 0;
    int bnum = 0;
    for(char ch : a)
    {
        if('0' <= ch && ch <= '9')
        {
            anum += ch-'0';
        }
    }
    for(char ch : b)
    {
        if('0' <= ch && ch <= '9')
        {
            bnum += ch-'0';
        }
    }

    if(anum != bnum)
    {
        return anum < bnum;
    }

    return a < b;
}

int main()
{
    int n;
    cin >> n;
    vector <string> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), comp);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}