#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> k >> n;
    for(int i = 1; i < n; i++)
    {
        cout << i << "\n";
        k -= i;
    }
    cout << k;
}