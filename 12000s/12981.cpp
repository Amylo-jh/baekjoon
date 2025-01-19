#include <iostream>

using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;

    int answer = 0;
    if(r && g && b)
    {
        int diff = min(r, min(g, b));
        answer += diff;
        r -= diff;
        g -= diff;
        b -= diff;
    }

    answer += r/3 + g/3 + b/3;
    r %= 3;
    g %= 3;
    b %= 3;

    if(r == g)
    {
        answer += r;
        r = g = 0;
    }
    else if(g == b)
    {
        answer += g;
        g = b = 0;
    }
    else if(b == r)
    {
        answer += b;
        b = r = 0;
    }

    answer += min(r, 1);
    answer += min(g, 1);
    answer += min(b, 1);

    cout << answer;
}