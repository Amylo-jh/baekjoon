#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <pair <long long, long long>> num;

long long get_patty(long long n, long long x)
{
    if(n == 0)
    {
        if(x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(x == 1)
    {
        return 0;
    }

    if(x <= num[n-1].first + 1)
    {
        return get_patty(n-1, x-1);
    }
    else if(x == num[n-1].first + 2)
    {
        return num[n-1].second + 1;
    }
    else if(x < num[n].first)
    {
        return num[n-1].second + 1 + get_patty(n-1, x - num[n-1].first - 2);
    }
    else if(x == num[n].first)
    {
        return num[n].second;
    }
}

int main()
{
    long long n, x;
    cin >> n >> x;
    
    num.resize(51);
    num[0] = {1, 1};
    for(int i = 1; i <= 50; i++)
    {
        num[i].first = num[i-1].first * 2 + 3;
        num[i].second = num[i-1].second * 2 + 1;
    }

    cout << get_patty(n, x);
}