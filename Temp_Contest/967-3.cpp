#include <iostream>

using namespace std;

int main()
{
    long long n, cat = 0, count = 0;
    cin >> n;

    while(cat < n)
    {
        if(cat == 0)
        {
            cat++;
            count++;
        }
        else
        {
            cat *= 2;
            count++;
        }
    }
    
    cout << count;   
}