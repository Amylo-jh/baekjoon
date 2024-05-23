#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <bool> is_prime(1000001, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 1000000; i++)
    {
        if(is_prime[i])
        {
            for(int j = i*2; j <= 1000000; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    long long answer = -1;
    long long num = 0;
    while(n--)
    {
        cin >> num;
        if(is_prime[num])
        {
            if(answer == -1)
            {
                answer = num;
            }
            else
            {
                answer = lcm(answer, num);
            }
        }
    }

    cout << answer;    
}