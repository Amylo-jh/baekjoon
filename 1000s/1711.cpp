#include <iostream>
#include <vector>

using namespace std;

long long pythagoras(pair <long long, long long> a, pair <long long, long long> b)
{
    long long dist1 = ((a.first - b.first) * (a.first - b.first));
    long long dist2 = ((a.second - b.second) * (a.second - b.second));
    return dist1 + dist2;
}

int main()
{
    int n;
    cin >> n;
    vector <pair <long long, long long>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    int count = 0;
    for(int i = 0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                long long dist1 = pythagoras(arr[i], arr[j]);
                long long dist2 = pythagoras(arr[j], arr[k]);
                long long dist3 = pythagoras(arr[k], arr[i]);
                if(dist1 + dist2 == dist3 || dist1 + dist3 == dist2 || dist2 + dist3 == dist1)
                {
                    count++;
                }
            }
        }
    }
    cout << count;
}