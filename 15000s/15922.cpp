#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    long long total_length = 0;
    long long pos = -1000000000;

    for(int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        total_length += max(0LL, b - (max(pos, a)));
        pos = max(pos, b);
    }
    cout << total_length;
}