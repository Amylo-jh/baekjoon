#include <iostream>

using namespace std;

int main()
{
    int n = 1;
    int input;
    cin >> input;

    while(input != 1)
    {
        if(input%2)
        {
            input = input * 3 + 1;
        }
        else
        {
            input = input/2;
        }

        n++;
    }
    
    cout << n;
}