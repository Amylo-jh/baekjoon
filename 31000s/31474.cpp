#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    long long answer = 1;
    cin >> n;

    for(int i = n/2+1; i <= n; i++)
    {
        answer *= i;
    }
    answer /= pow(2, n/2);
    cout << answer;
}