#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int s1 = 0, s2 = 0;
    vector <vector <int>> board(2, vector <int> (9, 0));
    bool is_win = false;

    for(int i = 0; i < 9; i++)
    {
        cin >> board[0][i];
    }
    for(int i = 0; i < 9; i++)
    {
        cin >> board[1][i];
    }

    for(int i = 0; i < 9; i++)
    {
        s1 += board[0][i];
        if(s1 > s2)
        {
            is_win = true;
        }
        s2 += board[1][i];
    }

    if(is_win && s1 < s2)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}