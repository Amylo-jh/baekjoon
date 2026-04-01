#include <iostream>

using namespace std;

int main()
{
    int donut, n;
    cin >> donut >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        int tmp;
        cin >> ch >> tmp;
        if (ch == '+')
        {
            donut += tmp;
        }
        else
        {
            donut -= tmp;
        }
    }
    cout << donut;
}