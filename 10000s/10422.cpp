#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> num(2501);

    num[0] = 1;
    num[1] = 1;

    for(int i = 2; i <= 2500; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            num[i] += num[i-j] * num[j-1];
            num[i] %= 1000000007;
        }
    }

    int query;
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> query;

        if(query % 2)
        {
            cout << "0\n";
        }
        else
        {
            query /= 2;
            cout << num[query] << "\n";
        }
    }
}