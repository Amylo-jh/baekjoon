#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    cin >> n >> d;
    
    //price, satisfaction
    vector <pair <int, int>> present(n);

    for(int i = 0; i < n; i++)
    {
        cin >> present[i].first >> present[i].second;
    }
    sort(present.begin(), present.end());

    int l = 0;
    int r = 0;
    long long sum = 0;
    long long max_v = 0;

    while(l <= r && r < n)
    {
        if(present[r].first - present[l].first < d)
        {
            sum += present[r].second;
            r++;
        }
        else
        {
            sum -= present[l].second;
            l++;
        }

        if(sum > max_v)
        {
            max_v = sum;
        }
    }

    cout << max_v;
}