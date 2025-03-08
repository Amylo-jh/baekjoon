#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++)
    {
        string str;
        deque <char> dq;
        cin >> str;
        dq.push_front(str[0]);
        for(int i = 1; i < str.length(); i++)
        {
            if(str[i] >= dq.front())
            {
                dq.push_front(str[i]);
            }
            else
            {
                dq.push_back(str[i]);
            }
        }

        cout << "Case #" << t << ": ";
        for(int i = 0; i < str.length(); i++)
        {
            cout << dq.front();
            dq.pop_front();
        }
        cout << "\n";
    }
}