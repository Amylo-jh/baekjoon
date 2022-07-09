#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    vector <bool> bit;
    int length = 1;
    int k;
    cin >> k;
    
    k--;
    
    int n = 1;
    while(k - pow(2, n) >= 0)
    {
        k = k - pow(2, n);
        length++;
        n++;   
    }

    for(int i = 0; i < length; i++)
    {
        if(k % 2)
        {
            bit.push_back(true);
        }
        else
        {
            bit.push_back(false);
        }
        k = k / 2;
    }
    
    int j = 0;
    for(int i = length - 1; i >= 0; i--)
    {
        if(bit[i])
        {
            cout << 7;
        }
        else
        {
            cout << 4;
        }
    }
}