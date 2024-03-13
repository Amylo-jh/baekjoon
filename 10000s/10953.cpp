#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        int a = str[0] - '0';
        int b = str[2] - '0';
        cout << a+b << "\n";
    }
}