#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        string str;
        cin >> n >> str;

        long long count = 0;
        stack <int> stk;

        for(int i = 0; i < n; i++)
        {
            if(str[i] == 'T')
            {
                if(stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    int diff = i - stk.top();
                    if(diff % 2 == 0)
                    {
                        stk.push(i);
                    }
                    else
                    {
                        count += diff;
                        stk.pop();
                    }
                }
            }
        }

        if(stk.empty())
        {
            cout << count << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}