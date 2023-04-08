#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <vector <int>> row_cumulative_sum;
    vector <vector <int>> col_cumulative_sum;

    row_cumulative_sum.resize(n);
    for(int i = 0; i < n; i++)
    {   
        row_cumulative_sum[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> row_cumulative_sum[i][j];
        }
    }
    col_cumulative_sum = row_cumulative_sum;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            row_cumulative_sum[i][j] += row_cumulative_sum[i][j-1];
            col_cumulative_sum[j][i] += col_cumulative_sum[j-1][i];
        }
    }
    
    string result;
    int sum_nutrient = 0;

    int y = (n / 2) - 1;
    int x = (n / 2) - 1;
    int width = 2;
    int height = 2;
    
    while(1)
    {
        //up, down, left, right;
        int nutrient[4] = {};
        string strs[4] = {"U","D","L","R"};

        //up
        if(y == 0)
        {
            nutrient[0] = 0;
        }
        else
        {
            if(x == 0)
            {
                nutrient[0] = row_cumulative_sum[y-1][x+width-1];
            }
            else
            {
                nutrient[0] = row_cumulative_sum[y-1][x+width-1] - row_cumulative_sum[y-1][x-1];
            }
        }

        //down
        if(y + height == n)
        {
            nutrient[1] = 0;
        }
        else
        {
            if(x == 0)
            {
                nutrient[1] = row_cumulative_sum[y+height][x+width-1];
            }
            else
            {
                nutrient[1] = row_cumulative_sum[y+height][x+width-1] - row_cumulative_sum[y+height][x-1];
            }
        }

        //left
        if(x == 0)
        {
            nutrient[2] = 0;
        }
        else
        {
            if(y == 0)
            {
                nutrient[2] = col_cumulative_sum[y+height-1][x-1];
            }
            else
            {
                nutrient[2] = col_cumulative_sum[y+height-1][x-1] - col_cumulative_sum[y-1][x-1];
            }
        }

        //right
        if(x + width == n)
        {
            nutrient[3] = 0;
        }
        else
        {
            if(y == 0)
            {
                nutrient[3] = col_cumulative_sum[y+height-1][x+width];
            }
            else
            {
                nutrient[3] = col_cumulative_sum[y+height-1][x+width] - col_cumulative_sum[y-1][x+width];
            }
        }

        int max_val = 0;
        int index = -1;
        for(int i = 0; i < 4; i++)
        {
            if(max_val < nutrient[i])
            {
                max_val = nutrient[i];
                index = i;
            }
        }

        if(index == -1)
        {
            break;
        }
        else if(index == 0)
        {
            sum_nutrient += nutrient[0];
            y--;
            height++;
            result += "U";
        }
        else if(index == 1)
        {
            sum_nutrient += nutrient[1];
            height++;
            result += "D";
        }
        else if(index == 2)
        {
            sum_nutrient += nutrient[2];
            x--;
            width++;
            result += "L";
        }
        else if(index == 3)
        {
            sum_nutrient += nutrient[3];
            width++;
            result += "R";
        }
    }

    cout << sum_nutrient << "\n";
    cout << result;
}