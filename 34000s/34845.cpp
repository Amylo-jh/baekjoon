#include <iostream>

using namespace std;

int main()
{
    int n, m, sum = 0, tmp, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
    }
    while(sum < n*m)
    {
        sum += 100;
        n++;
        cnt++;
    }
    cout << cnt;
}