#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    while(tc--)
    {
        vector <bool> arr(26, false);
        string str;
        getline(cin, str);
        for(int i = 0; i < str.length(); i++)
        {
            if('a' <= str[i] && str[i] <= 'z')
            {
                arr[str[i] - 'a'] = true;
            }
            else if('A' <= str[i] && str[i] <= 'Z')
            {
                arr[str[i] - 'A'] = true;
            }
        }

        bool flag = true;
        for(int i = 0; i < 26; i++)
        {
            if(!arr[i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout << "pangram\n";
        }
        else
        {
            cout << "missing ";
            for(int i = 0; i < 26; i++)
            {
                if(!arr[i])
                {
                    cout << (char)(i + 'a');
                }
            }
            cout << "\n";
        }
    }
}