#include <iostream>

using namespace std;

int main()
{
    int n;
    long long answer = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        answer += i*i*i;
    }
    cout << answer;
}