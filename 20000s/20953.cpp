#include <iostream>

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
        long long a, b;
        cin >> a >> b;
        cout << (a+b) * (a+b) * (a+b-1) / 2 << "\n";
    }
}