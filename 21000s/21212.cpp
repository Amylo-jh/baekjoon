#include <iostream>

using namespace std;

int main()
{
    int n, a, b, answer = INT32_MAX;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        answer = min(answer, b/a);
    }
    cout << answer;
}