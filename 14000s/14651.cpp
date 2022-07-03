#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 1)
    {
        cout << 0;
    }
    else if(n == 2)
    {
        cout << 2;
    }
    else
    {
        long long answer = 2;
        for(int i = 3; i <= n; i++)
        {
            answer *= 3;
            answer %= 1000000009;
        }

        cout << answer;
    }
}