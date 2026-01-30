#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    while (1)
    {
        string str;
        cin >> str;
        if (str == "#")
        {
            break;
        }
        queue<char> q1, q2;
        for (auto ch : str)
        {
            q1.push(ch);
        }
        while (!q1.empty())
        {
            char ch = q1.front();
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                break;
            }
            q1.pop();
            q2.push(ch);
        }
        while (!q1.empty())
        {
            cout << q1.front();
            q1.pop();
        }
        while (!q2.empty())
        {
            cout << q2.front();
            q2.pop();
        }
        cout << "ay\n";
    }
}