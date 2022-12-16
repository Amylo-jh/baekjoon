#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, n;
    cin >> n >> k;

    vector <int> choco(n);
    for(int i = 0; i < n; i++)
    {
        cin >> choco[i];
    }

    int day = 0;
    int eat_choco = 0;
    for(int i = 1; i < n; i++)
    {
        if(choco[0] != choco[i])
        {
            day++;
        }
        eat_choco += choco[i] - choco[0];
    }

    cout << eat_choco << " " << day;    
}