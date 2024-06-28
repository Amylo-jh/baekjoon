#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        int num = i;

        while(num)
        {
            sum += num % 10;
            num /= 10;
        }

        if(i % sum == 0)
        {
            answer++;
        }
    }

    cout << answer;
}