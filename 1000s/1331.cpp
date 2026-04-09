#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> calc_pos(string pos)
{
    int x, y;
    y = pos[0] - 'A';
    x = pos[1] - '1';
    return {y, x};
}

bool verify_pos(pair<int, int> prev_pos, pair<int, int> curr_pos)
{
    int dy = abs(prev_pos.first - curr_pos.first);
    int dx = abs(prev_pos.second - curr_pos.second);
    if ((dy == 2 && dx == 1) || (dy == 1 && dx == 2))
    {
        return true;
    }
    return false;
}

int main()
{
    vector<vector<bool>> chess(6, vector<bool>(6));
    pair<int, int> prev_pos, curr_pos, first_pos;
    string pos;
    cin >> pos;
    prev_pos = calc_pos(pos);
    first_pos = prev_pos;
    chess[prev_pos.first][prev_pos.second] = true;
    for (int i = 1; i < 36; i++)
    {
        cin >> pos;
        curr_pos = calc_pos(pos);
        if (!verify_pos(prev_pos, curr_pos))
        {
            cout << "Invalid";
            return 0;
        }
        if (chess[curr_pos.first][curr_pos.second])
        {
            cout << "Invalid";
            return 0;
        }
        chess[curr_pos.first][curr_pos.second] = true;
        prev_pos = curr_pos;
    }
    if(!verify_pos(first_pos, curr_pos))
    {
        cout << "Invalid";
        return 0;
    }
    cout << "Valid";
}