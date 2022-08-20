#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    bool flag = true;

    cin >> n >> str;

    char str2 = str[0];

    for(int i = 1; i < 2*n; i++)
    {
        if(str[i] == str2)
        {
            flag = false;
            break;
        }
        else
        {
            str2 = str[i];
        }
    }

    if(flag)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}