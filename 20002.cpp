#include <stdio.h>
#include <limits.h>

using namespace std;

int main()
{
    int farm[300][300] = {0};
    int sum[300][300] = {0};
    int farmsize = 0;
    int profit = 0;
    int max_profit = INT_MIN;

    scanf("%d", &farmsize);

    for(int y = 0; y < farmsize; y++)
    {
        for(int x = 0; x < farmsize; x++)
        {
            scanf("%d", &farm[y][x]);
        }
    }

    for(int y = 0; y < farmsize; y++)
    {
        for(int x = 0; x < farmsize; x++)
        {
            if(x == 0)
            {
                sum[y][x] = farm[y][x];
            }
            else{
                sum[y][x] = sum[y][x-1] + farm[y][x];
            }
        }
    }

    for(int harvest_size = 1; harvest_size <= farmsize; harvest_size++)
    {
        for(int startpos_y = 0; startpos_y <= (farmsize - harvest_size); startpos_y++)
        {
            for(int startpos_x = 0; startpos_x <= (farmsize - harvest_size); startpos_x++)
            {
                profit = 0;
                
                for(int lines = 0; lines < harvest_size; lines++)
                {
                    if(startpos_x == 0)
                    {
                        profit = profit + sum[startpos_y + lines][startpos_x + harvest_size-1];
                    }
                    else
                    {
                        profit = profit + sum[startpos_y + lines][startpos_x + harvest_size-1] - sum[startpos_y + lines][startpos_x-1];
                    }
                }
                if(max_profit < profit)
                {
                    max_profit = profit;
                }
            }
        }
    }

    printf("%d", max_profit);
}