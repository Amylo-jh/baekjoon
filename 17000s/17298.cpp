#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack <pair <int, int>> stk;
    vector <int> ans(n);

    stk.push({arr[0], 0});
    for(int i = 1; i < n; i++)
    {
        while(!stk.empty() && stk.top().first < arr[i])
        {
            ans[stk.top().second] = arr[i];
            stk.pop();
        }

        stk.push({arr[i], i});
    }

    while(!stk.empty())
    {
        ans[stk.top().second] = -1;
        stk.pop();
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}