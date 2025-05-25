#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int answer = INT32_MAX;
    for(int i = 0; i < n; i++)
    {
        int tmp, sum = 0;
        for(int j = 0; j < 3; j++)
        {
            cin >> tmp;
            sum += tmp;
        }
        if(sum >= 512 )
        {
            answer = min(answer, sum);
        }
    }

    if(answer == INT32_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}