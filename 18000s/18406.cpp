#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp = n;
    int length = 0;
    while(temp)
    {
        length++;
        temp /= 10;
    }

    int value = 0;

    for(int i = 0; i < length / 2; i++)
    {
        int temp = n % 10;
        n /= 10;
        value += temp;
    }

    for(int i = 0; i < length / 2; i++)
    {
        int temp = n % 10;
        n /= 10;
        value -= temp;
    }

    if(value == 0)
    {
        cout << "LUCKY";
    }
    else
    {
        cout << "READY";
    }
}