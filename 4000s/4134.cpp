#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        long long num;
        cin >> num;
        bool flag = false;
        while (!flag)
        {
            flag = true;
            if(num < 2)
            {
                num++;
                flag = false;
                continue;
            }
            if(num == 2 || num == 3)
            {
                flag = true;
                continue;
            }
            else if(num % 2 == 0 || num % 3 == 0)
            {
                num++;
                flag = false;
                continue;
            }
            for (long long i = 5; i * i <= num; i += 2)
            {
                if (num % i == 0)
                {
                    flag = false;
                    num++;
                    break;
                }
            }
        }
        cout << num << "\n";
    }
}