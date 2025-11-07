#include <iostream>
#include <string>

using namespace std;

pair <int, int> rsp(string a, string b)
{
    if(a == b)
    {
        return {0, 0};
    }
    else if(a == "R" && b == "S")
    {
        return {1, 0};
    }
    else if(a == "S" && b == "P")
    {
        return {1, 0};
    }
    else if(a == "P" && b == "R")
    {
        return {1, 0};
    }
    return {0, 1};
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        string a, b;
        pair <int, int> score, result;
        for(int i = 0; i < n; i++)
        {
            cin >> a >> b;
            result = rsp(a, b);
            score.first += result.first;
            score.second += result.second;
        }

        if(score.first == score.second)
        {
            cout << "TIE\n";
        }
        else if(score.first > score.second)
        {
            cout << "Player 1\n";
        }
        else
        {
            cout << "Player 2\n";
        }
    }
}