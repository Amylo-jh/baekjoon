#include <iostream>

using namespace std;

int main()
{
    int a, b, count = 0;
    cin >> a >> b;
    while(1)
    {
        b += a;
        if(b >= 5)
        {
            if(count % 2)
            {
                cout << "yj";
            }
            else
            {
                cout << "yt";
            }
            break;
        }
        swap(a, b);
        count++;
    }
}