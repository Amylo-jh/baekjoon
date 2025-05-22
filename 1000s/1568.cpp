#include <iostream>

using namespace std;

int main()
{
    int n;
    int cnt = 0;
    int curr = 1;
    cin >> n;

    while(n)
    {
        if(n >= curr)
        {
            n -= curr;
            curr++;
            cnt++;
        }
        else
        {
            curr = 1;
        }
    }

    cout << cnt;
}