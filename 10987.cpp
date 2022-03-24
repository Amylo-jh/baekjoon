#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int n = str.length();
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        char chr = str[i];
        switch (chr)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        {
            total++;
        }
        default:
            continue;
        }
    }

    cout << total;
}