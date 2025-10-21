#include <iostream>

using namespace std;

int main()
{
    int a, b, answer = 0, sum = 0;
    cin >> a >> b;
    for(int i = 1; i <= a; i++)
    {
        sum += i;
    }
    answer = sum;
    for(int i = a+1; i <= b; i++)
    {
        sum += i;
        answer *= sum;
        answer %= 14579;
    }
    cout << answer;
}