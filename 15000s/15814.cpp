#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int n;
    cin >> str >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        char tmp = str[a];
        str[a] = str[b];
        str[b] = tmp;
    }

    cout << str;
}