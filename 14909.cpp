#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int total = 0;
    int temp = 0;

    while(true)
    {
        cin >> temp;
        if(cin.eof())
        {
            break;
        }
        if (temp > 0)
        {
            total++;
        }
    }

    printf("%d", total);
}