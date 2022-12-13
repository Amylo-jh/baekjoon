#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector <bool> used(n+1);
    vector <int> num(n+1);

    int counter = n;
    int round = 1;
    while(k >= counter)
    {
        num[round] = counter;
        used[counter] = true;
        round++;
        counter--;
        k -= counter;
    }

    num[n-k] = counter;
    used[counter] = true;

    counter = 1;
    for(int i = 1; i <= n; i++)
    {
        if(num[i] != 0)
        {
            cout << num[i] << " ";
        }
        else
        {
            cout << counter << " ";
            counter++;
        }
    }
}