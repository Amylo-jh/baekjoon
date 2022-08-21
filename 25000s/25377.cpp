#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int min_time = 9999999;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a <= b)
        {
            min_time = min(min_time, b);
        }
    }

    if(min_time == 9999999)
    {
        cout << -1;
    }
    else
    {
        cout << min_time;
    }
}