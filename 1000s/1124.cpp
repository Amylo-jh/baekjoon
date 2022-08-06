#include <iostream>
#include <vector>

using namespace std;

vector <int> prime = {2,3,5,7};

void get_prime()
{
    for(int i = 11; i <= 100000; i++)
    {   
        bool flag = true;
        for(int j : prime)
        {
            if(i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    get_prime();

    int a, b;
    cin >> a >> b;

    int under_prime = 0;



    for(int i = a; i <= b; i++)
    {
        int j = i;
        
        int index = 0;
        int sub_count = 0;
        while(j != 1)
        {
            if(j % prime[index] == 0)
            {
                j = j / prime[index];
                sub_count++;
                index = 0;
                continue;
            }
            index++;
        }

        for(int k = 0; prime[k] <= sub_count; k++)
        {
            if(sub_count == prime[k])
            {
                under_prime++;
                break;
            }
        }
    }

    cout << under_prime;
}