#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    unordered_set <string> keyword;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        keyword.insert(str);
    }

    for(int i = 0; i < m; i++)
    {
        string str;
        string after_str = "";
        cin >> str;

        bool flag = true;
        while(flag)
        {
            flag = false;
            for(int j = 0; j < str.length(); j++)
            {
                if(str[j] == ',')
                {
                    after_str = str.substr(j + 1, str.length() - j - 1);
                    str = str.substr(0, j);
                    auto iter = keyword.find(str);
                    if(iter != keyword.end())
                    {
                        keyword.erase(iter);
                    }
                    str = after_str;
                    flag = true;
                    break;
                }
            }
        }
        auto iter = keyword.find(str);
        if(iter != keyword.end())
        {
            keyword.erase(iter);
        }

        cout << keyword.size() << "\n";
    }
}