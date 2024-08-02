#include <iostream>
#include <vector>
#include <set>
#include <queue> 

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
        long long n, k, sum = 0;
        cin >> n >> k;

        multiset <long long> planet;
        priority_queue <long long> conquest_queue;
        for(int i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            planet.insert(temp);
            sum += temp;
        }

        int count = 0;
        while(1)
        {
            if(sum <= k)
            {
                cout << count << "\n";
                break;
            }
            
            auto it = --planet.upper_bound(k);
            if(it == planet.end())
            {
                it--;
            }
            if(k < *it)
            {
                cout << "-1\n";
                break;
            }
            else
            {
                k += *it;
                sum -= *it;
                count++;
                planet.erase(it);
            }
        }
    }
}