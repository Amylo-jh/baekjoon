#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> g1;
vector <long long> g2;
vector <long long> arr;

void dfs(int start, int end, vector <long long>& vec, long long sum)
{
    if(start > end)
    {
        vec.push_back(sum);
        return;
    }
    
    dfs(start+1, end, vec, sum);
    dfs(start+1, end, vec, sum + arr[start]);
}

int main()
{
    int n, c;
    cin >> n >> c;

    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dfs(0, n/2, g1, 0);
    dfs(n/2+1, n-1, g2, 0);
    sort(g2.begin(), g2.end());

    long long answer = 0;
    for(int i = 0; i < g1.size(); i++)
    {
        answer += upper_bound(g2.begin(), g2.end(), c - g1[i]) - g2.begin();
    }

    cout << answer;
}