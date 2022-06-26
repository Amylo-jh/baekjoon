#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;


vector <bool> num = {false, false, true, true}; // 0, 1, 2 ,3

void init_prime_number(int n)
{
    for(int i = 4; i <= n; i++)
    {
        num.push_back(true);
    }

    for(int i = 2; i <= floor(sqrt(n)); i++)
    {
        if(num[i])
        {
            for(int j = 2; j * i <= n; j++)
            {
                num[i*j] = false;
            }
        }
    }
}

int main()
{
    init_prime_number(10000);

    int x, y;
    cin >> x >> y;

    int min_prime = 0;
    int prime_sum = 0;

    for(int i = x; i <= y; i++)
    {
        if(num[i])
        {
            min_prime = i;
            break;
        }
    }

    for(int i = y; i >= x; i--)
    {
        if(num[i])
        {
            prime_sum += i;
        }
    }

    if(min_prime == 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        cout << prime_sum << "\n" << min_prime;
    }
}