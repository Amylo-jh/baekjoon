#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        vector<long long> arr(n + 1);
        stack<long long> stk;
        long long answer = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i == n)
            {
                arr[i] = 0;
            }
            else
            {
                cin >> arr[i];
            }
            while (!stk.empty() && arr[i] < arr[stk.top()])
            {
                long long height = arr[stk.top()];
                stk.pop();
                long long length = i;
                if (!stk.empty())
                {
                    length = i - stk.top() - 1;
                }
                answer = max(answer, length * height);
            }
            stk.push(i);
        }
        cout << answer << "\n";
    }
}