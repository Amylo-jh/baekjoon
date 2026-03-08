#include <iostream>

using namespace std;

int main()
{
    int a[3] = {0, 0, 0};
    int tmp;
    for(int i = 0; i < 3; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    if(a[1] > a[2])
    {
        cout << 1;
    }
    else
    {
        cout << 2;
    }
}