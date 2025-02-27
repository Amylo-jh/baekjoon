#include <iostream>

using namespace std;

int answer = 0;

void recursion(int n, int num, bool isStart)
{
    if(n)
    {
        num *= 10;
        if(isStart)
        {
            for(int i = 1; i < 3; i++)
            {
                recursion(n-1, num+i, false);
            }
        }
        else
        {
            for(int i = 0; i < 3; i++)
            {
                recursion(n-1, num+i, false);
            }
        }
    }
    else if(num % 3 == 0)
    {
        answer++;
    }
}

int main()
{
    int n;
    cin >> n;

    recursion(n, 0, true);

    cout << answer;
}