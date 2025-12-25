#include <iostream>

using namespace std;

int main()
{
    int n, k, tmp;
    cin >> n >> k;
    while(k--)
    {
        cin >> tmp;
        n -= (tmp+1)/2;
    }
    if(n <= 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}