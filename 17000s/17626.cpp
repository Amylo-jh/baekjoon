#include <iostream>
#include <vector>

using namespace std;

int calc(int i, int ii, int iii, int iiii)
{
    return i*i + ii*ii + iii*iii + iiii*iiii;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < 225; i++)
    {
        for(int ii = 0; ii < 225; ii++)
        {
            for(int iii = 0; iii < 225; iii++)
            {
                for(int iiii = 0; iiii < 225; iiii++)
                {
                    int sum = calc(i, ii, iii, iiii);
                    if(sum == n)
                    {
                        cout << bool(i) + bool(ii) + bool(iii) + bool(iiii);
                        return 0;
                    }
                    else if(sum > n)
                    {
                        break;
                    }
                }
            }
        }
    }
}