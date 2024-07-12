#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a=0, b=0;
    string str;
    cin >> a >> str;

    a = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'A')
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    if(a > b)
    {
        cout << "A";
    }
    else if(a < b)
    {
        cout << "B";
    }
    else
    {
        cout << "Tie";
    }
}