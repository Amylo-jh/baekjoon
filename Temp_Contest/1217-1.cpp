#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector <vector <int>> arr(2);
    arr[0].resize(n);
    arr[1].resize(n);

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }


    int line1 = 0;
    int line2 = 0;
    int sum1 = 0;
    int sum2 = 0;

    if(n % 2) // 홀수
    {

    }
    else
    {
        for(int i = (n/2)+1; i < n; i++)
        {
            line1 += arr[0][i];
        }
        for(int i = 0; i < n/2; i++)
        {
            line2 += arr[1][i];
        }

        if(line1 < line2)
        {
            
        }
        else if(line2 < line1)
        {

        }
        else
        {

        }
    }
    for(int i = (n-1)/2+1; i < n; i++)
    {
        line1 += arr[0][i];
    }

}