#include <iostream>

using namespace std;

void count_zero(int num, int *count)
{
    if (num == 0)
    {
        *count += 1;
    }

    while(num != 0)
    {
        if(num % 10 == 0)
        {
            *count += 1;
        }
        num = num / 10;
    }

    return;
}

int main()
{
    int n, m;
    int t;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> n >> m;
        int total = 0;

        for(int j = n; j <= m; j++)
        {
            count_zero(j, &total);
        }

        cout << total << endl;
    }
}