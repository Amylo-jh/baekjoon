#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        long long n;
        cin >> n;
        string str = to_string(n);
        reverse(str.begin(), str.end());
        long long reversed_n = stoll(str);
        long long sqrtn = sqrt(n);
        long long sqrt_rn = sqrt(reversed_n);

        if(sqrtn*sqrtn == n && sqrt_rn*sqrt_rn == reversed_n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}