#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <vector <long long>> arr(4);
    int n;
    cin >> n;
    arr[0].resize(n);
    arr[1].resize(n);
    arr[2].resize(n);
    arr[3].resize(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> arr[j][i];
        }
    }
    vector <long long> ab;
    vector <long long> cd;
    ab.reserve(n*n);
    cd.reserve(n*n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ab.push_back(arr[0][i] + arr[1][j]);
            cd.push_back(arr[2][i] + arr[3][j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    long long counter = 0;
    for(int i = 0; i < n*n; i++)
    {
        long long value = -ab[i];
        int lo = lower_bound(cd.begin(), cd.end(), value) - cd.begin();
        int hi = upper_bound(cd.begin(), cd.end(), value) - cd.begin();
        counter += hi - lo;
    }

    cout << counter;
}