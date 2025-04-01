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

        char ch = str[0];
        int count = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ch)
            {
                count++;
            }
            else
            {
                cout << count << " " << ch << " ";
                ch = str[i];
                count = 1;
            }
        }
        cout << count << " " << ch << "\n";
    }
}