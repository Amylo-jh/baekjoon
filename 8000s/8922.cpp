#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;
        vector <int> num1(n);
        vector <int> num2(n);

        for(int i = 0; i < n; i++)
        {
            cin >> num1[i];
        }

        for(int q = 0; q < 1000; q++)
        {
            for(int i = 0; i < n-1; i++)
            {
                num2[i] = num1[i] - num1[i+1];
                if(num2[i] < 0)
                {
                    num2[i] *= -1;
                }
            }
            num2[n-1] = num1[n-1] - num1[0];
            if(num2[n-1] < 0)
            {
                num2[n-1] *= -1;
            }

            num1 = num2;
        }

        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(num1[i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout << "ZERO\n";
        }
        else
        {
            cout << "LOOP\n";
        }
    }
}