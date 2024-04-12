#include <iostream>

using namespace std;

int main()
{
    long long s, k;
    long long result = 1;
    cin >> s >> k;

    while(k > 0)
    {
        long long num = s / k;
        if(s % k != 0)
        {
            num++;
        }
        result *= num;
        s -= num;
        k--;
    }

    cout << result;
}