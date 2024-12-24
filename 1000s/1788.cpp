#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> pos_pib(1000001, 0);
    vector <long long> neg_pib(1000001, 0);
    pos_pib[1] = 1;
    pos_pib[0] = 0;
    neg_pib[1] = 1;

    int n;
    cin >> n;
    for(int i = 2; i <= abs(n); i++)
    {
        pos_pib[i] = (pos_pib[i-1] + pos_pib[i-2]) % 1000000000;
        neg_pib[i] = (neg_pib[i-2] - neg_pib[i-1]) % 1000000000;
    }

    if(n == 0)
    {
        cout << "0\n";
        cout << "0";
        return 0;
    }
    else if(n > 0)
    {
        cout << "1\n";
        cout << pos_pib[n];
    }
    else if(n < 0)
    {
        n = abs(n);
        if(neg_pib[n] < 0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << "1\n";
        }
        cout << abs(neg_pib[n]);
    }
}