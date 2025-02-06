#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    double min_value = __DBL_MAX__;
    int answer = 0;

    for(int i = 1; i <= tc; i++)
    {
        double a, b, c;
        cin >> a >> b >> c;

        double value = a / (c-b);
        if(value < min_value)
        {
            min_value = value;
            answer = i;
        }
    }

    cout << answer;
}