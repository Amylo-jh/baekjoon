#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if(n >= 6)
    {
        cout << "Love is open door";
    }
    else
    {
        int a;
        cin >> a;
        for(int i = 2; i <= n; i++)
        {
            cout << (a+1)%2 << "\n";
            a++;
        }
    }
}