#include <iostream>

using namespace std;

int main()
{
    int a, b;

    while(true)
    {
        cin >> a >> b;
        if(cin.eof())
        {
            break;
        }
        printf("%d\n", a+b);
    }
}