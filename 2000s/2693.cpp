#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[10];
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &arr[j]);
        }

        sort(arr, arr + 10);

        printf("%d\n", arr[7]);
    }
}