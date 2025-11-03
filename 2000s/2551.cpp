#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, tmp;
    cin >> n;
    vector <int> count(10001);
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        count[tmp]++;
    }
    int avg1 = 0, avg2 = 0;
    long long mindist1 = INT64_MAX, mindist2 = INT64_MAX;
    for(int i = 1; i <= 10000; i++)
    {
        long long dist1 = 0, dist2 = 0;
        for(int j = 1; j <= 10000; j++)
        {
            dist1 += 1LL * count[j] * abs(i-j);
            dist2 += 1LL * count[j] * (i-j) * (i-j);
        }
        if(mindist1 > dist1)
        {
            mindist1 = dist1;
            avg1 = i;
        }
        if(mindist2 > dist2)
        {
            mindist2 = dist2;
            avg2 = i;
        }
    }

    cout << avg1 << " " << avg2;
}