#include <iostream>

using namespace std;

int main()
{
    int temp;
    int total = 0;

    while(1)
    {
        cin >> temp;
        if(temp == -1)
            break;
        total = total + temp;
    }
    cout << total;
    
}