#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;

void init(int start, int seq, stack <int> stk)
{    
    if(seq > 0)
    {
        for(int i = start+1; i <= (n - seq + 1); i++)
        {
            stk.push(i);
            init(i, seq-1, stk);
            stk.pop();
        }
    }
    else
    {
        stack <int> temp_stk;
        while(!stk.empty())
        {
            temp_stk.push(stk.top());
            stk.pop();
        }
        while(!temp_stk.empty())
        {
            cout << temp_stk.top() << " ";
            temp_stk.pop();
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= (n - m + 1); i++)
    {
        stack <int> stk;
        stk.push(i);
        init(i, m-1, stk);
    }
}