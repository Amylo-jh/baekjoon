#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        string str, tmp;
        getline(cin, str);
        stack<string> stk;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                stk.push(tmp);
                tmp = "";
                continue;
            }
            tmp += str[i];
        }
        stk.push(tmp);

        cout << "Case #" << t << ": ";
        while (!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << "\n";
    }
}