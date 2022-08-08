#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <bool> prime(1003002);

void get_prime()
{
    int root = sqrt(prime.size());
    for(int i = 2; i <= root; i++)
    {   
        if(prime[i])
        {
            for(int j = i+i; j < prime.size(); j = j+i)
            {
                prime[j] = false;
            }
        }
    }
}

bool is_palindrome(int a)
{
    int orig = a;

    int b = 0;
    while(a)
    {
        b *= 10;
        b += a % 10;
        a /= 10;
    }

    if(orig == b)
    {
        return true;
    }

    return false;
}

int main()
{
    fill_n(prime.begin(), prime.size(), true);
    prime[0] = false;
    prime[1] = false;
    get_prime();

    int a;
    cin >> a;

    int i = a;
    while(true)
    {
        if(prime[i] && is_palindrome(i))
        {
            cout << i;
            break;
        }
        i++;
    }
}