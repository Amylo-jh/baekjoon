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
        long long n, div = 888888888888888888;
        int count = 0;
        cin >> n;
        while(div)
        {
            count += n / div;
            n %= div;
            div /= 10;
        }

        if(n)
        {
            cout << "No\n";
            continue;
        }
        if(count <= 8)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}