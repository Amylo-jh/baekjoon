#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long hi = n*n;
    long long lo = 1;
    long long answer = 0;
    while(lo <= hi)
    {
        long long count = 0;
        long long mid = (hi+lo)/2;

        for(long long i = 1; i <= n; i++)
        {
            count += min(mid/i, n);
        }

        if(count < k)
        {
            lo = mid+1;
        }
        else
        {
            answer = mid;
            hi = mid-1;
        }
    }

    cout << answer;
}