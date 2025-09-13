#include <iostream>
#include <vector>

using namespace std;

#define DIV 1000000007;

int main()
{
    vector <long long> dp1(1000001);
    vector <long long> dp2(1000001);
    dp1[1] = 7;
    dp1[2] = 33;
    dp2[1] = 3;
    dp2[2] = 13;
    for(int i = 3; i <= 1000000; i++)
    {
        dp1[i] = (dp1[i-1] * 3 + dp2[i-1] * 4) % DIV;
        dp2[i] = (dp1[i-1] + dp2[i-1] * 2) % DIV;
    }

    int tc, n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        cout << dp1[n] << "\n";
    }
}