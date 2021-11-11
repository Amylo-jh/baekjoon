#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int x;
    int position[7] = {0};
    int sticks = 0;

    cin >> x;

    for(int i = 0; i < 7; i++)
    {
        position[i] = (x & int(pow(2, i))) == int(pow(2,i));
        sticks = sticks + position[i];
    }

    cout << sticks;
}