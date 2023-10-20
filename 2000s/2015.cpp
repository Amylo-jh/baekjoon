#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector <int> arr(n+1);
    vector <int> sum(n+1);
    unordered_map <int, long long> map;
    long long answer = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] += sum[i-1] + arr[i];
        if(sum[i] == k)
        {
            answer++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        answer += map[sum[i] - k];
        map[sum[i]]++;
    }

    cout << answer;
}