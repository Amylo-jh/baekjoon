#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int a = 97;

    for(int i = 0; i < 26; i++)
    {
        bool flag = false;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == a)
            {
                cout << j << " ";
                flag = true;
                break;
            }
        }

        if(flag == false)
        {
            cout << "-1 ";
        }
        a++;
    }
}