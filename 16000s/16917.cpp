#include <iostream>

using namespace std;

int main()
{
    int a, b, c, x, y, answer = 0;
    cin >> a >> b >> c >> x >> y;
    if(a+b > 2*c)
    {
        answer += min(x, y) * 2 * c;
        if(x < y)
        {
            y -= x;
            x = 0;
        }
        else
        {
            x -= y;
            y = 0;
        }
    }
    if(a > 2*c)
    {
        answer += 2*c * x;
        x = 0;
    }
    if(b > 2*c)
    {
        answer += 2*c * y;
        y = 0;
    }
    answer += a * x;
    answer += b * y;
    cout << answer;
}