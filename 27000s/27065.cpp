#include <iostream>
#include <vector>

using namespace std;

vector <int> num(5001);
// 1 = 부족수
// 2 = 완전수
// 3 = 과잉수


int main()
{
    for(int i = 1; i <= 5000; i++)
    {
        int sum = 0;
        for(int j = 1; j < i; j++)
        {
            if(i % j == 0)
            {
                sum += j;
            }
        }

        if(sum < i)
        {
            num[i] = 1;
        }
        else if(sum == i)
        {
            num[i] = 2;
        }
        else if(sum > i)
        {
            num[i] = 3;
        }
    }

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;

        if(num[n] == 3)
        {
            bool flag = true;
            for(int i = 1; i < n; i++)
            {
                if(n % i == 0)
                {
                    if(num[i] == 3)
                    {
                        flag = false;
                    }
                }
            }

            if(flag)
            {
                cout << "Good Bye\n";
            }
            else
            {
                cout << "BOJ 2022\n";
            }
        }
        else
        {
            cout << "BOJ 2022\n";
        }
    }
}