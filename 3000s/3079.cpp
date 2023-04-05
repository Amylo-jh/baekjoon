#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m;
    cin >> n >> m;

    long long max_time = 0;
    
    vector <int> evaluator(n);
    for(int i = 0; i < n; i++)
    {
        cin >> evaluator[i];
        max_time = max((long long)evaluator[i], max_time);
    }

    long long hi = max_time * m;
    long long lo = 1;
    long long answer = 0;
    
    while(lo <= hi)
    {
        long long mid = lo + (hi-lo)/ 2;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += mid / evaluator[i];
            if(sum > m)
            {
                break;
            }
        }

        if(sum < m)
        {
            lo = mid + 1;
        }
        else
        {
            answer = mid;
            hi = mid - 1;
        }
    }

    cout << answer;
}