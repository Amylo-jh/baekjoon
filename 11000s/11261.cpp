#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, w;
        cin >> n >> w;
        vector <int> curr(w+1), next(w+1);
        // weight, preference
        vector <pair <int, int>> weapon(n);
        for (auto& [a, _] : weapon)
        {
            cin >> a;
        }
        for (auto& [_, b] : weapon)
        {
            cin >> b;
        }
        sort(weapon.begin(), weapon.end());

        for(int i = 0; i < n; i++)
        {
            auto [weight, value] = weapon[i];
            for(int j = 0; j <= w; j++)
            {
                if(j-weight < 0)
                {
                    next[j] = curr[j];
                }
                else
                {
                    next[j] = max(curr[j], curr[j-weight]+value);
                }
            }
            swap(curr, next);
        }
        cout << curr[w] << "\n";
    }
}