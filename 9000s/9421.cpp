#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <set>

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

bool is_prime_sangun_number(int i)
{
    set <int> cycle;
    cycle.insert(i);
    bool flag = false;

    while(1)
    {
        int sum = 0;
        while(i)
        {
            int digit = i % 10;
            i = i / 10;
            sum += digit * digit;
        }
        
        if(sum == 1)
        {
            flag = true;
            break;
        }
        else
        {
            if(auto [iterator, success] = cycle.insert(sum); success == false)
            {
                break;
            }
            else
            {
                i = sum;
            }
        }
    }

    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init_prime_number(1000000);

    int n;
    cin >> n;

    for(int i = 7; i < n; i++)
    {
        if(num[i])
        {
            if(is_prime_sangun_number(i))
            {
                cout << i << "\n";
            }
        }
    }
}