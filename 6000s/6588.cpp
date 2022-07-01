#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init_prime_number(1000000);

    while(1)
    {
        int n;
        cin >> n;

        if(n == 0)
        {
            break;
        }

        int a = 0;
        int b = 0;
        int diff = n;
        for(int i = 2; i <= n; i++)
        {
            if(num[i] && num[n-i])
            {
                a = i;
                b = n-i;
                break;
            }
        }

        if(a != 0)
        {
            cout << n << " = " << a << " + " << b << "\n";
        }
        else
        {
            cout << "Goldbach's conjecture is wrong." << "\n";
        }
    }
}