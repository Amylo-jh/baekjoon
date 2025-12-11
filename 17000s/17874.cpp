#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << max(a, n-a) * max(b, n-b) * 4;
}