#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool num[1000001];
    int range = 1000000;
    memset(num, true, range);

    num[0] = false;
    num[1] = false;
    num[2] = true;

    for(int i = 2; i * 2 < range; i++)
    {
        if(num[i])
        {
            for(int j = 2; j * i <= range; j++)
            {
                num[j * i] = false;
            }
        }
    }

    int n, m;
    cin >> n >> m;

    for(int i = n; i <= m; i++)
    {
        if(num[i])
        {
            cout << i << "\n";
        }
    }
}