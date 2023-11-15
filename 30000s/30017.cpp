#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << min(a, b+1) + min(a-1, b);
}