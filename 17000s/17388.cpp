#include <iostream>

using namespace std;

int main()
{
    int s, k, h;
    cin >> s >> k >> h;

    int min = s;
    int n = 1;

    if(min > k)
    {
        min = k;
        n = 2;
    }
    if(min > h)
    {
        min = h;
        n = 3;
    }

    if(s + k + h >= 100)
    {
        cout << "OK";
    }
    else
    {
        switch (n)
        {
        case 1:
            cout << "Soongsil";
            break;
        
        case 2:
            cout << "Korea";
            break;
        
        case 3:
            cout << "Hanyang";
            break;
            
        default:
            break;
        }
    }
}