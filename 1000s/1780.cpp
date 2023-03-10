#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> paper;
vector <int> result(3);
int n;

bool check(int y, int x, int paper_size)
{
    int value = paper[y][x];
    bool return_value = true;

    for(int i = y; i < y + paper_size; i++)
    {
        for(int j = x; j < x + paper_size; j++)
        {
            if(paper[i][j] != value)
            {
                i = j = n;
                return_value = false;
            }
        }
    }

    return return_value;
}

void init(int y, int x, int paper_size)
{
    if(check(y, x, paper_size))
    {
        int value = paper[y][x];
        result[value + 1]++;
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                init(y + (paper_size/3)*i, x + (paper_size/3)*j, paper_size/3);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    paper.resize(n);
    for(int i = 0; i < n; i++)
    {
        paper[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    init(0, 0, n);

    for(int i = 0; i < 3; i++)
    {
        cout << result[i] << "\n";
    }
}