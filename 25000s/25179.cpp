#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    if((n-1) % (m+1))
    {
        cout << "Can win";
    }
    else
    {
        cout << "Can't win";
    }
}