#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int s, c;
    cin >> s >> c;

    vector <int> scallion (s);
    int low = 1;
    int high = 0;
    long long sum = 0;
    
    for(int i = 0; i < s; i++)
    {
        cin >> scallion[i];
        high = max(high, scallion[i]);
        sum += scallion[i];
    }

    long long mid = (high + low) / 2;
    int count = 0;

    while (low <= high)
    {
        count = 0;
        for(int i = 0; i < s; i++)
        {
            count += scallion[i] / mid;
        }

        if(count >= c)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }

        mid = (low + high) / 2;
    }

    cout << sum - mid * c;
}