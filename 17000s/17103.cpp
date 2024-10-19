#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    vector <bool> prime(1000001, true);
    vector <int> prime_list;
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= 1000000; i++)
    {
        if(prime[i] == true)
        {
            prime_list.push_back(i);
            for(int j = i*2; j <= 1000000; j += i)
            {
                prime[j] = false;
            }
        }
    }

    while(tc--)
    {
        int n;
        int count = 0;
        cin >> n;

        for(int i : prime_list)
        {
            if(i > n/2)
            {
                break;
            }
            if(prime[n-i] == true)
            {
                count++;
            }
        }
        cout << count << "\n";
    }
}