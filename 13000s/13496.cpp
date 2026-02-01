#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++)
    {
        int n, s, d, di, vi, sum = 0;
        cin >> n >> s >> d;
        for(int i = 0; i < n; i++)
        {
            cin >> di >> vi;
            if(di <= s*d)
            {
                sum += vi;
            }
        }
        cout << "Data Set " << t << ":\n";
        cout << sum << "\n\n";
    }
}