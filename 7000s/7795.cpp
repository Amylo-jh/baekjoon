#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int n, m;
        cin >> n >> m;
        vector <int> a(n);
        vector <int> b(m);
        
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int count = 0;
        for(int i = 0; i < m; i++)
        {
            auto iter = upper_bound(a.begin(), a.end(), b[i]);
            int diff = a.end() - iter;
            count += diff;
        }

        cout << count << endl;
    }
}