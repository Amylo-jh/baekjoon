#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        cout << str << "\n";
    }
}