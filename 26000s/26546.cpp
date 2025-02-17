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
        int s, e;
        cin >> str >> s >> e;

        for(int i = 0; i < str.length(); i++)
        {
            if(s <= i && i < e)
            {
                continue;
            }
            else
            {
                cout << str[i];
            }
        }
        cout << "\n";
    }
}