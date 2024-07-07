#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int q, n;
    cin >> q >> n;

    vector <int> v1(n);
    vector <int> v2(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    if(q == 1)
    {
        sort(v2.begin(), v2.end());
    }
    else
    {
        sort(v2.begin(), v2.end(), greater<int>());
    }

    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += max(v1[i], v2[i]);
    }

    cout << sum;
}