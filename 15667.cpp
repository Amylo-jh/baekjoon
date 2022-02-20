#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    n--;
    for(int i = 1; i < 101; i++)
    {
        if(n == i * (i+1))
        {
            cout << i;
            break;
        }
    }
}