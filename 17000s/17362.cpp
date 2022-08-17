#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int j = (n-1) / 4;
    int k = (n-1) % 4;

    if(j % 2)
    {
        cout << 5-k;
        return 0;
    }
    else
    {
        cout << k+1;
    }
}