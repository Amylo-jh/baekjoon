#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack <int> stk;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int command;
        cin >> command;
        if(command == 1)
        {
            int num;
            cin >> num;
            stk.push(num);
            continue;
        }
        else if(command == 2)
        {
            if(stk.empty())
            {
                cout << -1;
            }
            else
            {
                cout << stk.top();
                stk.pop();
            }
        }
        else if(command == 3)
        {
            cout << stk.size();
        }
        else if(command == 4)
        {
            cout << stk.empty();
        }
        else
        {
            if(stk.empty())
            {
                cout << -1;
            }
            else
            {
                cout << stk.top();
            }
        }
        cout << '\n';
    }
}