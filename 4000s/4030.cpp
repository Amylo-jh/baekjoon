#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <long long> arr;   
    long long sum = 1;
    for(int i = 1; sum <= 1e9; i++)
    {
        sum += i;
        int sqrt_sum = int(sqrt(sum));
        if(sum == sqrt_sum*sqrt_sum)
        {
            arr.push_back(sum);
        }
    }

    int a, b;
    for(int i = 1;; i++)
    {
        cin >> a >> b;
        if(a == 0 && b== 0)
        {
            break;
        }
        a++;
        b--;

        int lo_pos = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
        int hi_pos = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
        cout << "Case " << i << ": " << hi_pos - lo_pos << "\n";
    }
}