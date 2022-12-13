#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int n;
        cin >> n;
        vector <string> strs(n);

        for(int i = 0; i < n; i++)
        {
            cin >> strs[i];
        }        

        string str_answer = "";
        bool flag_found = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || flag_found)
                {
                    continue;
                }
                
                string temp_str = strs[i] + strs[j];
                bool flag = true;

                for(int k = 0; k < temp_str.length(); k++)
                {
                    if(temp_str[k] != temp_str[temp_str.length() - k - 1])
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag)
                {
                    str_answer = temp_str;
                    flag_found = true;
                }
            }
        }

        if(flag_found)
        {
            cout << str_answer << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}