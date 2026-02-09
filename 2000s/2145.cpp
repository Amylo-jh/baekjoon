#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int n, sum = 0;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        while (1)
        {
            while (n)
            {
                sum += n % 10;
                n /= 10;
            }
            if (sum < 10)
            {
                break;
            }
            n = sum;
            sum = 0;
        }
        cout << sum << "\n";
    }
}