#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int l = 1, r = 1;
    while(n--)
    {
        if(l < r)
        {
            l++;
        }
        else if(l > r)
        {
            r++;
        }
        else
        {
            l++;
        }
    }

    cout << l*r;
}