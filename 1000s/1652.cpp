#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <vector <bool>> area(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(n);
        string str;
        cin >> str;
        for(int j = 0; j < n; j++)
        {
            if(str[j] == '.')
            {
                area[i][j] = true;
            }
            else
            {
                area[i][j] = false;
            }
        }
    }

    int count_1 = 0;
    for(int i = 0; i < n; i++)
    {
        int prev_dot = -1;
        for(int j = 0; j < n; j++)
        {
            if(area[i][j] == false)
            {
                if(j - prev_dot > 2)
                {
                    count_1++;
                }
                prev_dot = j;
            }
        }
        if(n - prev_dot > 2)
        {
            count_1++;
        }
    }

    int count_2 = 0;
    for(int i = 0; i < n; i++)
    {
        int prev_dot = -1;
        for(int j = 0; j < n; j++)
        {
            if(area[j][i] == false)
            {
                if(j - prev_dot > 2)
                {
                    count_2++;
                }
                prev_dot = j;
            }
        }
        if(n - prev_dot > 2)
        {
            count_2++;
        }
    }

    cout << count_1 << " " << count_2;
}