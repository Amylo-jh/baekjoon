#include <iostream>
#include <string>

using namespace std;

int main()
{
    int min_level = INT32_MAX, n, tmp;
    string answer, str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str >> tmp;
        if (tmp < min_level)
        {
            min_level = tmp;
            answer = str;
        }
    }
    cout << answer;
}