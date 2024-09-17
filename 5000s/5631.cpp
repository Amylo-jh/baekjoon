#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int tc = 1;; tc++)
    {
        int n, ax, ay, bx, by, q, r1, r2;
        cin >> n;

        if(n == 0)
        {
            break;
        }
        vector <pair <int, int>> house(n);
        vector <long long> dist1(n);
        vector <long long> dist2(n);
        for(int i = 0; i < n; i++)
        {
            cin >> house[i].first >> house[i].second;
        }
        cin >> ax >> ay >> bx >> by >> q;
        for(int i = 0; i < n; i++)
        {
            dist1[i] = (long long)(house[i].first-ax)*(house[i].first-ax) + (long long)(house[i].second-ay)*(house[i].second-ay);
            dist2[i] = (long long)(house[i].first-bx)*(house[i].first-bx) + (long long)(house[i].second-by)*(house[i].second-by);
        }
        sort(dist1.begin(), dist1.end());
        sort(dist2.begin(), dist2.end());

        cout << "Case " << tc << ":\n";
        for(int i = 0; i < q; i++)
        {
            cin >> r1 >> r2;
            r1 *= r1;
            r2 *= r2;

            int count1, count2, sum;
            count1 = upper_bound(dist1.begin(), dist1.end(), r1) - dist1.begin();
            count2 = upper_bound(dist2.begin(), dist2.end(), r2) - dist2.begin();

            sum = count1 + count2;

            cout << max(0, n - sum) << '\n';
        }
    }
}