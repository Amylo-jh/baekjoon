#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    
    while(tc--)
    {
        long long num = 0;
        cin >> num;

        long long hi = 2e8;
        long long lo = 0;
        while(lo < hi)
        {
            long long mid = (hi + lo) / 2;
            long long sum = mid * (mid + 1) / 2;
            long long diff = num - sum;
            
            if(diff < 0)
            {
                hi = mid;
            }
            else if(diff <= mid)
            {
                cout << mid << "\n";
                break;
            }
            else
            {
                lo = mid+1;
            }
        }
    }
}