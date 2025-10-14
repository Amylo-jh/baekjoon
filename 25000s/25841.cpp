#include <iostream>

using namespace std;

int main()
{
    int a, b, c, count = 0;
    cin >> a >> b >> c;
    for(int i = a; i <= b; i++)
    {
        int num = i;
        while(num)
        {
            if(num % 10 == c)
            {
                count++;
            }
            num /= 10;
        }
    }
    cout << count;
}