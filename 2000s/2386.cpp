#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string s, str;
        cin >> s;
        if(s == "#")
        {
            break;
        }

        char ch = s[0];
        int count = 0;

        getline(cin, str);
        for(char c : str)
        {
            if(tolower(c) == ch)
            {
                count++;
            }
        }

        cout << ch << " " << count << '\n';
    }
}