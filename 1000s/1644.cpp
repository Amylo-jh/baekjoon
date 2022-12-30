#include <iostream>
#include <vector>

using namespace std;

int max_num;
vector <bool> prime_bool;
vector <long long> sum_prime = {0};

void init_prime()
{
    for(int i = 2; i <= max_num; i++)
    {
        prime_bool[i] = true;
    }

    for(int i = 2; i <= max_num; i++)
    {
        if(prime_bool[i])
        {
            int temp = 2;
            while(i * temp <= max_num)
            {
                prime_bool[i*temp] = false;
                temp++;
            }
            sum_prime.push_back(i);
        }
    }
    prime_bool = {};

    for(int i = 1; i < sum_prime.size(); i++)
    {
        sum_prime[i] += sum_prime[i-1];
    }
}

int main()
{
    max_num = 4000000;
    prime_bool.resize(max_num+1);
    init_prime();

    int n;
    cin >> n;

    int counter = 0;

    for(int i = 0; i < sum_prime.size(); i++)
    {
        for(int j = i+1; j < sum_prime.size(); j++)
        {
            if(sum_prime[j] - sum_prime[i] > max_num)
            {
                break;
            }
            else if(sum_prime[j] - sum_prime[i] == n)
            {
                counter++;
            }
        }
    }

    cout << counter;
}