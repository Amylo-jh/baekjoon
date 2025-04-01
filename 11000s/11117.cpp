#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    
    while(tc--)
    {
        string str;
        cin >> str;
        vector <int> count(26, 0);
        for(int i = 0; i < str.length(); i++)
        {
            count[str[i] - 'A']++;
        }

        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            vector <int> temp = count;
            bool flag = true;
            for(int j = 0; j < str.length(); j++)
            {
                temp[str[j] - 'A']--;
                if(temp[str[j] - 'A'] < 0)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}