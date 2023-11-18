#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <long long> arr(n+1);
    vector <long long> cnt(m);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i-1] + arr[i];
        arr[i] %= m;
        cnt[arr[i]]++;
    }

    long long answer = cnt[0];
    for(int i = 0; i < m; i++)
    {
        long long cnum = cnt[i];
        answer += cnum * (cnum - 1) / 2;
    }
    cout << answer;    
}