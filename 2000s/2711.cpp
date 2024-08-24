#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int pos;
        string str;
        cin >> pos >> str;

        for(int i = 0; i < str.size(); i++)
        {
            if(i == pos - 1)
            {
                continue;
            }
            cout << str[i];
        }
        cout << "\n";
    }
}