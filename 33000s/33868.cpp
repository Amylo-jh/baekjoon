#include <iostream>

using namespace std;

int main()
{
    int n, min1 = INT32_MAX, max1 = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        max1 = max(max1, tmp1);
        min1 = min(min1, tmp2);
    }
    cout << (max1*min1)%7 + 1;
}