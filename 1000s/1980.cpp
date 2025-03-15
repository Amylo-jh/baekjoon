#include <iostream>

using namespace std;

int main()
{
    int n, m, t;
    int max_burger = 0;
    cin >> n >> m >> t;
    int min_time = t;

    if(n > m)
    {
        swap(n, m);
    }

    int remain_time;
    for(int i = 0; i*n <= t; i++)
    {
        remain_time = t - i*n;
        if(remain_time % m <= min_time)
        {
            min_time = remain_time % m;
            max_burger = max(max_burger, i + remain_time / m);
        }
    }

    cout << max_burger << " " <<  min_time;
}