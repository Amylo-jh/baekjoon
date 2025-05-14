#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        int tmp = i;
        while(tmp)
        {
            if(tmp % 10 == 3 || tmp % 10 == 6 || tmp % 10 == 9)
            {
                count++;
            }
            tmp /= 10;
        }
    }

    cout << count;
}