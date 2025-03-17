#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a, b;
    string d;
    cin >> a >> b >> d;
    vector <bool> is_prime(4000001, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= 4000000; i++)
    {
        if(is_prime[i])
        {
            for(int j = 2; j*i <= 4000000; j++)
            {
                is_prime[i*j] = false;
            }
        }
    }

    int cnt = 0;
    for(int i = a; i <= b; i++)
    {
        if(is_prime[i])
        {
            string str = to_string(i);
            if(str.find(d) != string::npos)
            {
                cnt++;
            }
        }
    }   

    cout << cnt;
}