#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
    }

    string str;
    cin >> str;
    
    for(int i = str.length() - 1; i >= 0; i--)
    {
        cout << str[i];
    }
}