#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, tmp, pos = 0;
    vector<int> lis;
    cin >> n >> tmp;
    lis.push_back(tmp);
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        if (tmp > lis[pos])
        {
            lis.push_back(tmp);
            pos++;
        }
        else
        {
            int p = lower_bound(lis.begin(), lis.end(), tmp) - lis.begin();
            lis[p] = tmp;
        }
    }
    cout << pos + 1;
}