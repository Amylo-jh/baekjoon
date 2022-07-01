#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> prime = {2,3,5,7};

    for(int i = 11; i <= 1000; i = i+2)
    {
        bool isprime = true;
        for(int j : prime)
        {
            int remainder = i % j;
            if(remainder == 0)
            {
                isprime = false;
                break;
            }
        }
        if(isprime)
        {
            prime.push_back(i);
        }
    }

    int num;
    cin >> num;
    int primenum = 0;

    for(int i = 0; i < num; i++)
    {
        int targetnum;;
        cin >> targetnum;

        if(find(prime.begin(), prime.end(), targetnum) != prime.end() )
        {
            primenum++;
        }
    }

    cout << primenum;
}