#include <iostream>
#include <vector>

using namespace std;

vector <int> chess;
int n;
int counter = 0;

bool check(int pos)
{
    for(int i = 0; i < pos; i++)
    {
        if(chess[pos] == chess[i] || pos - i == abs(chess[pos] - chess[i]))
        {
            return false;
        }
    }

    return true;
}

void nqueen(int pos)
{
    if(pos == n)
    {
        counter++;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        chess[pos] = i;
        if(check(pos))
        {
            nqueen(pos+1);
        }
    }
}

int main()
{
    cin >> n;
    chess.resize(n);

    nqueen(0);
    cout << counter;
}