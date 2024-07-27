#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int answer = 0;
    while(n--)
    {
        int num;
        cin >> num;
        answer = max(answer, num);
    }

    cout << answer;
}