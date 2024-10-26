#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int query;
    cin >> query;

    while(query--)
    {
        long long a, b;
        cin >> a >> b;

        if(b % a == 0 && b / a > 1)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        cout << "\n";
    }
}