#include <iostream>
#include <map>

using namespace std;

map <long long, long long> mp;

long long get_fun(long long num)
{

    if(mp.find(num) == mp.end())
    {
        long long n1 = num / 2;
        long long n2 = num - n1;

        get_fun(n1);
        get_fun(n2);

        mp[num] = n1*n2 + mp[n1] + mp[n2];
    }

    return mp[num];
}

int main()
{
    long long n;
    cin >> n;

    mp[1] = 0;
    mp[2] = 1;

    get_fun(n);
    cout << mp[n];
}