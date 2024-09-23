#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string str;
        getline(cin, str);

        if(str == "#")
        {
            break;
        }
        
        vector <string> tokens;
        string token = "";
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ')
            {
                tokens.push_back(token);
                token = "";
            }
            else
            {
                token += str[i];
            }
        }
        tokens.push_back(token);

        for(string s : tokens)
        {
            for(int i = 0; i < s.size(); i++)
            {
                if(i == 0 || i == s.size()-1)
                {
                    cout << s[i];
                }
                else
                {
                    cout << s[s.size()-i-1];
                }
            }
            cout << ' ';
        }
        cout << '\n';
    }
}