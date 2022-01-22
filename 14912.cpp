#include <iostream>

using namespace std;

int main()
{
    int n;
    int d;
    int answer = 0;
    cin >> n >> d;

    for(int i = 1; i <= n; i++)
    {
        int temp = i;
        while(temp != 0)
        {
            if(temp % 10 == d)
            {
                answer++;
            }
            temp = temp / 10;
        }
    }

    cout << answer;
}