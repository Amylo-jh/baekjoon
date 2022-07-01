#include <iostream>

using namespace std;

int main()
{
    int n;
    int answer = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int total = i;
        int num = i;

        while(num != 0)
        {
            total += num % 10;
            num = num / 10;
        }

        if(total == n)
        {
            answer = i;
            break;
        }
    }

    cout << answer;
}