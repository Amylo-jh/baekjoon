#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <int> arr(n);
    vector <int> dp;
    vector <int> lis(n);;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp.push_back(arr[0]);
    lis[0] = 0;
    
    int dp_size = 1;
    int index = 0;
    for(int i = 1; i < n; i++)
    {
        if(dp[dp_size-1] < arr[i])
        {
            dp.push_back(arr[i]);
            lis[i] = dp_size;
            dp_size++;
        }
        else
        {
            index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[index] = arr[i];
            lis[i] = index;
        }
    }

    cout << dp.size() << "\n";
    int counter = dp_size-1;
    vector <int> stack;
    for(int i = n-1; i >= 0; i--)
    {
        if(lis[i] == counter)
        {
            stack.push_back(arr[i]);
            counter--;
        }
    }
    for(int i = stack.size()-1; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
}