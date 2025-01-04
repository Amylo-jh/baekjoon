#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, m;
    cin >> n >> s >> m;

    vector <int> diff(n);
    for(int i = 0; i < n; i++)
    {
        cin >> diff[i];
    }

    vector <bool> curr(m+1, false);
    vector <bool> next(m+1, false);
    curr[s] = true;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(curr[j])
            {
                if(j - diff[i] >= 0)
                {
                    next[j - diff[i]] = true;
                }
                if(j + diff[i] <= m)
                {
                    next[j + diff[i]] = true;
                }
            }
        }
        curr = next;
        fill(next.begin(), next.end(), false);
    }

    int max_volume = -1;
    for(int i = m; i >= 0; i--)
    {
        if(curr[i])
        {
            max_volume = i;
            break;
        }
    }

    cout << max_volume;
}