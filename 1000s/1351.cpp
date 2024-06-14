#include <iostream>
#include <map>

using namespace std;

map <int, long long> mp;
long long n;
int p, q;

long long recursion(long long num)
{
    if(mp[num] != 0)
    {
        return mp[num];
    }

    return mp[num] = recursion(num/p) + recursion(num/q);
}

int main()
{
    cin >> n >> p >> q;
    mp[0] = 1;
    cout << recursion(n);
}