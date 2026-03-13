#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> answer;
    if (n % 2)
    {
        answer.push_back(n / 2 + 1);
        for (int i = 0; i < n / 2; i++)
        {
            answer.push_back(n - i);
            answer.push_back(n / 2 - i);
        }
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            answer.push_back(n / 2 - i);
            answer.push_back(n - i);
        }

    }
    for (int i : answer)
    {
        cout << i << " ";
    }
}