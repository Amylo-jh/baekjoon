#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long long max_sqrtnum = -1;

void check(long long num)
{
    int sqrt_num = (int)floor(sqrt(num));
    if(num == sqrt_num*sqrt_num)
    {
        max_sqrtnum = max(max_sqrtnum, num);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        string str;
        cin >> str;

        for(int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int dy = -n+1; dy < n; dy++)
            {
                for(int dx = -m+1; dx < m; dx++)
                {
                    int y = i;
                    int x = j;
                    long long curr_num = 0;
                    while(0 <= y && y < n && 0 <= x && x < m)
                    {
                        curr_num += arr[y][x];
                        check(curr_num);
                        curr_num *= 10;
                        if(dy == 0 && dy == dx)
                        {
                            break;
                        }
                        y += dy;
                        x += dx;
                    }
                }
            }
        }
    }

    cout << max_sqrtnum;
}