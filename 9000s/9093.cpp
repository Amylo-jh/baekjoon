#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    cin.ignore();
    while(tc--)
    {
        string str;
        getline(cin, str);

        string tmp;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
            {
                reverse(tmp.begin(), tmp.end());
                cout << tmp << " ";
                tmp = "";
            }
            else
            {
                tmp.push_back(str[i]);
            }
        }

        reverse(tmp.begin(), tmp.end());
        cout << tmp << " ";
        tmp = "";
        cout << "\n";
    }
}