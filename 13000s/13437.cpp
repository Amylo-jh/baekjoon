#include <iostream>

using namespace std;

int main()
{
    long long a, b, n, m, k;
    cin >> a >> b >> n >> m >> k;

    int temp = min(a, b);
    b = max(a, b);
    a = temp;
    long long answer = 0;

    if(k == 0 || k == 1 || k == 5 || k == 7)
    {
        cout << 0;
        return 0;
    }

    if(k == 2)
    {
        answer = a*a*4;
    }
    else if(k == 3)
    {
        answer = 8*(b-a)*a;
    }
    else if(k == 4)
    {
        answer += 2*a*(m-2*b);
        answer += 2*a*(n-2*b);
        answer += 4*(b-a)*(b-a);
    }
    else if(k == 6)
    {
        answer += 2*(m-2*b)*(b-a);
        answer += 2*(n-2*b)*(b-a);
    }
    else if(k == 8)
    {
        answer += (m-2*b)*(n-2*b);
    }

    cout << answer;
}