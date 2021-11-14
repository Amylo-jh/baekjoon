#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    int k = 0;
    int temp[100000];
    int sum[100000] = {0};
    int interval[100000] = {0};
    int max = INT32_MIN;

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp[i]);
        if(i == 0)
        {
            sum[i] = temp[i];
        }
        else
        {
            sum[i] = sum[i-1] + temp[i];
        }
    }

    for(int j = 0; j <= n - k; j++)
    {
        if(j == 0)
        {
            interval[j] = sum[j+k-1];
        }
        else
        {
            interval[j] = sum[j+k-1] - sum[j-1];
        }
        if(max < interval[j])
        {
            max = interval[j];
        }
    }
    
    cout << max;

}