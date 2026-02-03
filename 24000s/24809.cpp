#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int money = 0, answer = 0, tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        money += tmp;
        if (money < 0)
        {
            answer -= money;
            money = 0;
        }
    }
    cout << answer;
}