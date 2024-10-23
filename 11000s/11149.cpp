#include <iostream>
#include <string>

using namespace std;

char eval(string str)
{
    int sum = 0;
    for(int i = 0; i < str.length(); i++)
    {
        sum += str[i] - 'a';
    }

    sum %= 27;

    if(sum == 26)
    {
        return ' ';
    }
    return sum + 'a';
}

int main()
{
    int tc;
    cin >> tc;

    cin.ignore();
    while(tc--)
    {
        string str;
        getline(cin, str);

        string token;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
            {
                cout << eval(token);
                token = "";
            }
            else
            {
                token += str[i];
            }
        }
        cout << eval(token);
        cout << "\n";
    }
}