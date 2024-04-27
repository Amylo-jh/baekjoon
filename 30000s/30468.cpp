#include <iostream>

using namespace std;

int main()
{
    int n, k = 0, tmp;
    for(int i = 0; i < 4; i++)
    {
        cin >> tmp;
        k += tmp;
    }
    cin >> n;
    n *= 4;

    cout << max(0, n-k);
}