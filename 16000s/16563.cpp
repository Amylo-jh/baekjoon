#include <iostream>
#include <vector>

using namespace std;

vector <bool> is_prime;
vector <int> prime;
int max_value = 2300; // ???

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime.resize(max_value);
    is_prime[0] = true;
    is_prime[1] = true;
    for(int i = 2; i < max_value; i++)
    {
        if(!is_prime[i])
        {
            prime.push_back(i);
            for(int j = 2; j*i < max_value; j++)
            {
                is_prime[j*i] = true;
            }
        }
    }
    int prime_size = prime.size();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        int index = 0;
        while(num != 1)
        {
            if(num % prime[index] == 0)
            {
                cout << prime[index] << " ";
                num /= prime[index];
                index--;
            }
            if(num < prime[index] * prime[index])
            {
                cout << num;
                break;
            }
            index++;
        }
        cout << "\n";
    }    
}