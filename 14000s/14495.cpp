#include <iostream>

using namespace std;

int main()
{
    long long num[5] = {0,1,1,1,1};
    int n;
    cin >> n;

    for(int i = 4; i <= n; i++)
    {
        num[4] = num[1] + num[3];
        num[1] = num[2];
        num[2] = num[3];
        num[3] = num[4];
    }

    cout << num[4];
}