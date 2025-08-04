#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>

using namespace std;

bool compare(pair <long long, long long> a, pair <long long, long long> b)
{
    return a.second * b.first > a.first * b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;
    cin >> n >> m;
    vector <pair <long long, long long>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), compare);

    long long up = 0, down = 1;
    for(int i = 0; i < n; i++)
    {
        if(m == 0)
        {
            break;
        }

        long long amount = arr[i].first;
        long long sugar = arr[i].second;
        if(m >= amount)
        {
            m -= amount;
            up += sugar;
        }
        else
        {
            up *= amount;
            down *= amount;
            up += sugar*m;
            m = 0;
        }
    }

    long long gcd_num = gcd(up, down);
    up /= gcd_num;
    down /= gcd_num;
    cout << up << "/" << down;
}