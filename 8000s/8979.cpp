#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <vector <int>> medal(n, vector <int>(5));
    for(int i = 0; i < n; i++)
    {
        cin >> medal[i][3] >> medal[i][0] >> medal[i][1] >> medal[i][2];
    }
    sort(medal.begin(), medal.end(), greater<>());
    medal[0][4] = 1;
    int diff = 1;
    for(int i = 1; i < n; i++)
    {
        if(medal[i-1][0] == medal[i][0] && medal[i-1][1] == medal[i][1] && medal[i-1][2] == medal[i][2])
        {
            medal[i][4] = medal[i-1][4];
            diff++;
        }
        else
        {
            medal[i][4] = medal[i-1][4] + diff;
            diff = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(medal[i][3] == k)
        {
            cout << medal[i][4];
            return 0;
        }
    }
}