#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int m;
        cin >> m;

        int curr = 0;
        int sum = 0;
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            curr += a;
            curr -= b;
            sum += max(0, -curr);
            curr = max(0, curr);
        }
        cout << sum << "\n";
    }
}