#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    int b = 0, s = 0, a = 0;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'B')
        {
            b++;
        }
        else if(str[i] == 'S')
        {
            s++;
        }
        else if(str[i] == 'A')
        {
            a++;
        }
    }

    int max_value = max(b, max(s, a));
    bool flag = false;
    if(b == s && s == a)
    {
        cout << "SCU";
        return 0;
    }
    if(max_value == b)
    {
        cout << "B";
    }
    if(max_value == s)
    {
        cout << "S";
    }
    if(max_value == a)
    {
        cout << "A";
    }
}