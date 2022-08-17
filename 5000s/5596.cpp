#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    
    for(int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        a += temp;
    }

    for(int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        b += temp;
    }

    cout << max(a, b);
}