#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k, t;
    cin >> n >> k >> t;
    vector <long long> arr(n);
    stack <long long> big;
    stack <long long> small;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater());
    for(int i = 0; i < n; i++)
    {
            big.push(arr[i]);
    }


    while(k--)
    {
        while(!big.empty() && big.top() < t)
        {
            small.push(big.top());
            big.pop();
        }
        
        if(!small.empty())
        {
            t += small.top();
            small.pop();
        }
    }
    cout << t;
}