#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        int n, r;
        cin >> n >> r;
        if(n == 0 && r == 0)
        {
            break;
        }
        stack <int> stk;

        for(int i = 1; i <= n; i++)
        {
            stk.push(i);
        }

        for(int i = 0; i < r; i++)
        {
            int p, c;
            cin >> p >> c;

            stack <int> mix1;
            stack <int> mix2;

            for(int j = 0; j < p-1; j++)
            {
                mix1.push(stk.top());
                stk.pop();
            }
            for(int j = 0; j < c; j++)
            {
                mix2.push(stk.top());
                stk.pop();
            }

            while(!mix1.empty())
            {
                stk.push(mix1.top());
                mix1.pop();
            }
            while(!mix2.empty())
            {
                stk.push(mix2.top());
                mix2.pop();
            }
        }
        cout << stk.top() << "\n";
    }
}