#include <iostream>

using namespace std;

int main()
{
    int a, b, n, k;
    cin >> a >> b >> n >> k;
    k--;
    cout << (k / (b*n))+1 << " " << ((k % (b*n)) / n)+1;
}