#include <iostream>
#include <stack>
#include <vector>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> answer(n);
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // error check
    if(arr[0] != 1)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i < n; i++)
    {
        if(arr[i] - arr[i-1] > 1)
        {
            cout << -1;
            return 0;
        }
    }

    stack <int> stk;
    for(int i = n-1; i >= 0; i--)
    {
        while(!stk.empty() && stk.top() - 1 == arr[i])
        {
            answer[i]++;
            stk.pop();
        }
        stk.push(arr[i]);
    }

    for(auto i : answer)
    {
        cout << i << "\n";
    }
}