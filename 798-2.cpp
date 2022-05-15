#include <iostream>

using namespace std;

int main()
{
    int n;
    int answer = 1;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        answer = answer * i;
    }
    cout << answer;
}