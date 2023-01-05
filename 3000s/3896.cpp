#include <iostream>
#include <vector>

using namespace std;

int num = 1299709;
vector <bool> prime(num+1);

void init_prime()
{
    for(int i = 2; i <= num; i++)
    {
        prime[i] = true;
    }

    for(int i = 2; i <= num; i++)
    {
        if(prime[i])
        {
            int j = 2;
            while(i*j <= num)
            {
                prime[i*j] = false;
                j++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init_prime();

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;

        int counter = 0;

        int temp_num = n;

        while(!prime[temp_num])
        {
            counter++;
            temp_num--;
        }
        temp_num = n;
        while(!prime[temp_num])
        {
            counter++;
            temp_num++;
        }

        cout << counter << "\n";
    }
}