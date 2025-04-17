#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> dice;
int n;
int answer = 0;

int get_topidx(int diceidx, int value)
{
    if(value == 0)
    {
        return 5; 
    }
    else if(value == 1)
    {
        return 3;
    }
    else if(value == 2)
    {
        return 4;
    }
    else if(value == 3)
    {
        return 1;
    }
    else if(value == 4)
    {
        return 2;
    }
    else if(value == 5)
    {
        return 0;
    }
}

int get_bottomidx(int diceidx, int value)
{
    for(int i = 0; i < 6; i++)
    {
        if(dice[diceidx][i] == value)
        {
            return i;
        }
    }
}

int get_maxvalue(int diceidx, int curr_idx)
{
    vector <int> i = dice[diceidx];
    if(curr_idx == 0 || curr_idx == 5)
    {
        return max({i[1], i[2], i[3], i[4]});
    }
    else if(curr_idx == 1 || curr_idx == 3)
    {
        return max({i[0], i[2], i[4], i[5]});
    }
    else if(curr_idx == 2 || curr_idx == 4)
    {
        return max({i[0], i[1], i[3], i[5]});
    }
}

void solve(int curr_dice, int curr_idx, int curr_sum)
{
    int bottom_value = dice[curr_dice][curr_idx];
    int top_idx = get_topidx(curr_dice, curr_idx);
    int top_value = dice[curr_dice][top_idx];
    curr_sum += get_maxvalue(curr_dice, curr_idx);
    
    if(curr_dice == n-1)
    {
        answer = max(answer, curr_sum);
        return;
    }
    int next_bottomidx = get_bottomidx(curr_dice+1, top_value);
    solve(curr_dice+1, next_bottomidx, curr_sum);
}

int main()
{
    cin >> n;
    dice.resize(n);
    for(int i = 0; i < n; i++)
    {
        dice[i].resize(6);
        for(int j = 0; j < 6; j++)
        {
            cin >> dice[i][j];
        }
    }

    for(int i = 0; i < 6; i++)
    {
        solve(0, i, 0);
    }
    
    cout << answer;
}