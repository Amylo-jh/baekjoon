#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m, s, total_sec = 0;
    cin >> h >> m >> s;
    total_sec = 3600*h + 60*m + s;

    int query;
    cin >> query;
    while(query--)
    {
        int q, c;
        cin >> q;
        if(q == 1)
        {
            cin >> c;
            total_sec += c;
        }
        else if(q == 2)
        {
            cin >> c;
            total_sec -= c;
        }
        else if(q == 3)
        {
            while(total_sec < 0)
            {
                total_sec %= 86400;
                total_sec += 86400;
            }
            total_sec %= 86400;
            cout << total_sec/3600 << " " << (total_sec % 3600)/60 << " " << total_sec % 60 << "\n";
        }
    }
}