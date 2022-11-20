#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> num(31);

    num[0] = 1;
    num[1] = 1;

    for(int i = 2; i <= 30; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            num[i] += num[i-j] * num[j-1];
        }
    }

    int query;
    while(1)
    {
        cin >> query;
        if(!query)
        {
            break;
        }
        cout << num[query] << "\n";
    }
}