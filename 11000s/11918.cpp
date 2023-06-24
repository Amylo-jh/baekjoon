#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, l;
    cin >> n >> l;
    vector <pair <long long, long long>> light(n);
    for(int i = 0; i < n; i++)
    {
        long long pos;
        cin >> pos;
        light[i].first = pos - l;
        light[i].second = pos + l;
    }
    sort(light.begin(), light.end());

    long long last_l = light[0].first;
    long long result = 0;

    for(int i = 1; i < n; i++)
    {
        if(light[i].first < light[i-1].second)
        {
            result += light[i-1].second - max(light[i].first, last_l);
        }
        last_l = light[i-1].second;
    }

    cout << result;
}