#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set <string> token;
    token.insert(" ");
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        token.insert(str);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        token.insert(str);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        string str;
        cin >> str;
        token.erase(str);
    }

    int str_len;
    string str;
    cin >> str_len;
    cin.ignore();
    getline(cin, str);

    bool is_newline = true;
    for(int i = 0; i < str_len; i++)
    {
        string curr_str = str.substr(i, 1);
        if(token.find(curr_str) != token.end())
        {
            if(!is_newline)
            {
                cout << "\n";
                is_newline = true;
            }
        }
        else
        {
            cout << str[i];
            is_newline = false;
        }
    }
}