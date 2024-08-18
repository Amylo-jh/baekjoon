#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, p, num;
    cin >> n >> p;

    map <int, int> mp;
    mp[n] = 1;
    num = n;
    
    int i = 1;
    while(i++)
    {
        num = (num*n) % p;
        if(mp[num])
        {
            cout << i - mp[num];
            break;
        }
        else
        {
            mp[num] = i;
        }
    }
}