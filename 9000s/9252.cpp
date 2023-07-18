#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    a = "0" + a;
    b = "0" + b;

    int a_len = a.length();
    int b_len = b.length();
    vector <vector <int>> lcs(b_len);
    lcs[0].resize(a_len);
    for(int i = 1; i < b_len; i++)
    {
        lcs[i].resize(a_len);
        for(int j = 1; j < a_len; j++)
        {
            if(a[j] == b[i])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    cout << lcs[b_len-1][a_len-1] << "\n";

    if(lcs[b_len-1][a_len-1] == 0)
    {
        return 0;
    }

    stack <char> stk;
    int i = b_len-1;
    int j = a_len-1;

    while(lcs[i][j] != 0)
    {
        if(lcs[i][j] == lcs[i][j-1])
        {
            j--;
        }
        else if(lcs[i][j] == lcs[i-1][j])
        {
            i--;
        }
        else if(lcs[i][j]-1 == lcs[i-1][j-1])
        {
            stk.push(b[i]);
            i--;
            j--;
        }
    }

    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}