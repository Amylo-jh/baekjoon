#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector <int> coin(n);
    vector <int> coin_count(k+1);
    coin_count.assign(k+1,20000);

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coin[i] = temp;
        coin_count[temp] = 1;
    }

    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int next_coin = i + coin[j];
            if(next_coin <= k)
            {
                coin_count[next_coin] = min(coin_count[next_coin], coin_count[i] + 1);
            }
        }
    }

    if(coin_count[k] == 20000)
    {
        cout << -1;
    }
    else
    {
        cout << coin_count[k];
    }
}