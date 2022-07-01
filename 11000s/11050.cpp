#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int total = 1;

    for(int i = 0; i < k; i++)
    {
        total = total * (n-i);
        total = total / (i+1);
    }

    cout << total;
}