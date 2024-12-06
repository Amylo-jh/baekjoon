#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        string str;
        cin >> str;

        cout << str[0];
        for(int i = 1; i < str.size(); i++)
        {
            if(str[i] == str[i-1])
            {
                continue;
            }
            cout << str[i];
        }
        cout << "\n";
    }
}