#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> num(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    int diff = INT32_MAX;
    int p_first = 0;
    int p_second = 0;

    while(p_first < n && p_second < n)
    {
        if(num[p_first] - num[p_second] < m)
        {
            p_first++;
        }
        else
        {
            diff = min(diff, num[p_first] - num[p_second]);
            p_second++;
        }
    }

    cout << diff;
}