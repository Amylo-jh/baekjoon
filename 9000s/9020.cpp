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
    int tc;
    cin >> tc;

    init_prime_number(10000);

    for(int q = 0; q < tc; q++)
    {
        int n;
        cin >> n;

        int a;
        int b;
        int diff = n;
        for(int i = 2; i <= n; i++)
        {
            if(num[i] && num[n-i])
            {
                if(diff > abs(i - (n-i)))
                {
                    diff = abs(i - (n-i));
                    a = i;
                    b = n-i;
                }        
            }
        }

        cout << a << " " << b << endl;
    }
}