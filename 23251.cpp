#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for(int i = 0; i < tc; i++)
    {
        int k;
        cin >> k;
        cout << k* 23 << "\n";
    }
}