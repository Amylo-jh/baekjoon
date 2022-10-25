#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int n, m;
        cin >> n >> m;

        vector <bool> checked(101);
        vector <vector <int>> field(n);
        for(int i = 0; i < n; i++)
        {
            field[i].resize(m);
            for(int j = 0; j < m; j++)
            {
                cin >> field[i][j];
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int d_y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
                int d_x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

                if(field[i][j] == -1 || checked[field[i][j]])
                {
                    continue;
                }
                for(int k = 0; k < 8; k++)
                {
                    int y = i + d_y[k];
                    int x = j + d_x[k];

                    if(0 <= y && y < n && 0 <= x && x < m)
                    {
                        if(field[i][j] == field[y][x])
                        {
                            checked[field[i][j]] = true;
                        }
                    }
                }
            }
        }

        int count = 0;
        for(int i = 0; i <= 100; i++)
        {
            if(checked[i])
            {
                count++;
            }
        }

        cout << count << "\n";
    }
}