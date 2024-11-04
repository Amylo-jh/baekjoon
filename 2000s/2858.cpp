#include <iostream>

using namespace std;

int main()
{
    int r, b;
    cin >> r >> b;

    int num = r + b;
    for(int i = 1; i <= num; i++)
    {
        if(num % i == 0)
        {
            int j = num / i;
            if((i-2) * (j-2) == b)
            {
                cout << max(i, j) << " " << min(i, j);
                break;
            }
        }
    }
}