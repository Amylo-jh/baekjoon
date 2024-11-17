#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> cow;
vector <bool> is_prime;
vector <int> cow_prime;

void get_cow(int idx, int sum, int depth)
{
    if(depth == m)
    {
        if(is_prime[sum])
        {
            cow_prime.push_back(sum);
        }
        return;
    }
    for(int i = idx+1; i < n-m+depth+1; i++)
    {
        get_cow(i, sum+cow[i], depth+1);
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cow.push_back(x);
    }
    sort(cow.begin(), cow.end());


    is_prime.resize(10000, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < 10000; i++)
    {
        if(is_prime[i])
        {
            for(int j = 2; i*j < 10000; j++)
            {
                is_prime[i*j] = false;
            }
        }
    }

    for(int i = 0; i < n-m+1; i++)
    {
        get_cow(i, cow[i], 1);
    }

    if(cow_prime.empty())
    {
        cout << -1;
        return 0;
    }

    sort(cow_prime.begin(), cow_prime.end());
    cow_prime.erase(unique(cow_prime.begin(), cow_prime.end()), cow_prime.end());
    for(int i : cow_prime)
    {
        cout << i << " ";
    }


}