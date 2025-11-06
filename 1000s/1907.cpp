#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;
    // C, H, O
    vector <vector <int>> arr(3, vector <int>(3));
    int prev;
    int idx = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if('1' <= str[i] && str[i] <= '9')
        {
            arr[idx][prev] += str[i] - '1';
        }
        else if(str[i] == 'C')
        {
            prev = 0;
            arr[idx][0]++;
        }
        else if(str[i] == 'H')
        {
            prev = 1;
            arr[idx][1]++;
        }
        else if(str[i] == 'O')
        {
            prev = 2;
            arr[idx][2]++;
        }
        else if(str[i] == '+' || str[i] == '=')
        {
            idx++;
        }
    }

    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            for(int k = 1; k <= 10; k++)
            {
                vector <int> sum(3);
                sum[0] += arr[0][0]*i + arr[1][0]*j - arr[2][0]*k;
                sum[1] += arr[0][1]*i + arr[1][1]*j - arr[2][1]*k;
                sum[2] += arr[0][2]*i + arr[1][2]*j - arr[2][2]*k;
                if(!sum[0] && !sum[1] && !sum[2])
                {
                    cout << i << " " << j << " " << k;
                    i = j = k = 10;
                }
            }
        }
    }
}