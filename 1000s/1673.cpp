#include <iostream>

using namespace std;

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        int chicken = 0;

        while(n / k)
        {
            chicken += (n/k)*k;
            n = n - (n/k)*k + (n/k);
        }
        chicken += n;
        cout << chicken << "\n";
    }
}
