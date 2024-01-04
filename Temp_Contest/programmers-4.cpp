#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> cookie;
vector <vector <int>> arr;
vector <int> btrk;

void backtrack(int index, int n)
{
    if(n == 0)
    {
        for(int i = 1; i < btrk.size(); i++)
        {
            if(btrk[i-1] >= btrk[i])
            {
                return;
            }
        }
        
        arr.push_back(btrk);
        return;
    }
    for(int i = index+1; i < cookie.size()-n+1; i++)
    {
        btrk.push_back(cookie[i]);
        backtrack(i, n-1);
        btrk.pop_back();
    }
}

vector <int> solution(vector <int> cookies, int k)
{
    cookie = cookies;
    int n = cookies.size();
    int lis_size = 0;
    vector <int> dp;
    dp.push_back(cookies[0]);
    for(int i = 1; i < n; i++)
    {
        if(cookies[i] < dp[lis_size])
        {
            int index = lower_bound(dp.begin(), dp.end(), cookies[i]) - dp.begin();
            dp[index] = cookies[i];
        }
        else if(cookies[i] > dp[lis_size])
        {
            dp.push_back(cookies[i]);
            lis_size++;
        }    
    }
    lis_size = dp.size();

    for(int i = 0; i < n-lis_size+1; i++)
    {
        btrk.push_back(cookie[i]);
        backtrack(i, lis_size-1);
        btrk.pop_back();
    }
    
    vector <int> answer;
    sort(arr.begin(), arr.end());
    answer = arr[k-1];
    
    // for(int i : answer)
    // {
    //     cout << i << " ";
    // }
    return answer;
}

int main()
{
    vector <int> cookies;
    int n, k;
    cin >> n >> k;
    cookies.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> cookies[i];
    }
    solution(cookies, k);    
}


