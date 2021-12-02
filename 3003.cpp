#include <iostream>

using namespace std;

int main()
{
     int a[6];
    for(int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    
    cout << 1 - a[0] << " ";
    cout << 1 - a[1] << " ";
    cout << 2 - a[2] << " ";
    cout << 2 - a[3] << " ";
    cout << 2 - a[4] << " ";
    cout << 8 - a[5];
}