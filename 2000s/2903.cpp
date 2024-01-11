#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int number = 3;
    for(int i = 1; i < n; i++)
    {
        number = number*2 - 1;
    }

    cout << number * number;
}