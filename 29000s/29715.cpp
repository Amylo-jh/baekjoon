#include <iostream>

using namespace std;

long long combination(int n, int r)
{
    long long result = 1;
    while(r)
    {
        result *= n;
        n--;
        r--;
    }
    
    return result;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int other_hint = 0;
    int available_number = 9;
    long long total_time = 0;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(a != 0)
        {
            n--;
            available_number--;
        }
        else
        {
            other_hint++;
        }
    }

    if(other_hint)
    {
        long long count = combination(n, other_hint) * combination(available_number-other_hint, n-other_hint);
        total_time += count*x;
        total_time += ((count-1)/3)*y;
    }
    else
    {
        long long count = combination(available_number, n);
        total_time += count*x;
        total_time += ((count-1)/3)*y;
    }

    cout << total_time;
}