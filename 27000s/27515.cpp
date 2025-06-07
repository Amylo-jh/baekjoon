#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int query;
    cin >> query;

    long long value = 0;
    while(query--)
    {
        long long temp;
        cin >> temp;
        value += temp;

        long long answer = 1LL << 62;
        while(answer && !(answer & value))
        {
            answer = answer >> 1;
        }

        cout << answer << "\n";
    }
}