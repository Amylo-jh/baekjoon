#include <iostream>

using namespace std;

int main()
{
    int n, k;
    int coin[10];
    int i = 0;
    int count = 0;
    int tmp;

    cin >> n >> k;

    for (i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    for (i = n-1; i >=0 ; i--)
    {
        tmp = 0;
        tmp = k / coin[i];
        k = k % coin[i];
        count = count + tmp;
    }

    cout << count;
}