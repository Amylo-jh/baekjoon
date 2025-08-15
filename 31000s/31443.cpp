#include <iostream>

using namespace std;

int main()
{
    long long n, m, answer = 1, three, remain;
    cin >> n >> m;
    if(n < 3 && m < 3)
    {
        cout << n*m;
        return 0;
    }
    
    three = n*m / 3;
    remain = n*m % 3;
    if(remain == 1)
    {
        three--;
    }
    while(three--)
    {
        answer *= 3;
        answer %= 1000000007;
    }
    if(remain == 1)
    {
        answer *= 4;
    }
    else if(remain == 2)
    {
        answer *= 2;
    }
    answer %= 1000000007;

    cout << answer;
}