#include <iostream>
#include <math.h>

using namespace std;

void set(int length)
{
    if(length == 1)
    {
        cout << "-";
        return;
    }
        
    set(length/3);

    for(int i = 0; i < length/3; i++)
    {
        cout << " ";
    }
    set(length/3);   
}

int main()
{
    int n;
    while(true)
    {
        cin >> n;

        if(cin.eof() == true)
        {
            break;
        }
        set(pow(3, n));
        cout << endl;
    }
}