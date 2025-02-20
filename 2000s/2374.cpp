#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack <long long> stk;
    long long answer = 0;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        if(stk.empty())
        {
            stk.push(x);
        }
        else
        {
            
            if(stk.top() < x)
            {
                answer += x - stk.top();
                while(!stk.empty() && stk.top() < x)
                {
                    stk.pop();
                }
                stk.push(x);
            }
            else if(stk.top() > x)
            {
                stk.push(x);
            }
        }
    }

    while(stk.size() > 1)
    {
        long long x = stk.top();
        stk.pop();
        answer += stk.top() - x;
    }
    
    cout << answer;
}