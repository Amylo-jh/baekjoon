#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int sol(int seq, int r, int c, int n)
{
    if(n == 0)
    {
        return seq;
    }
    else
    {
        if(r < pow(2, n-1) && c < pow(2, n-1)) // 1사분면
        {
        }
        else if(r < pow(2, n-1) && c >= pow(2, n-1)) // 2사분면
        {
            seq += (pow(2, n-1) * pow(2, n-1));
            c -= pow(2, n-1);
        }
        else if(r >= pow(2, n-1) && c < pow(2, n-1)) // 3사분면
        {
            seq += (pow(2, n-1) * pow(2, n-1)) * 2;
            r -= pow(2, n-1);
        }
        else //4사분면
        {
            seq += (pow(2, n-1) * pow(2, n-1)) * 3;
            c -= pow(2, n-1);
            r -= pow(2, n-1);
        }
    }
    seq = sol(seq, r, c, n-1);

    return seq;
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;

    int seq = sol(0, r, c, n);
    cout << seq;
}