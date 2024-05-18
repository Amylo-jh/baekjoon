#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> arr;
vector <vector <vector <int>>> tetrominos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector <vector <int>> tetro;
    tetro = {{1, 1, 1, 1}};
    tetrominos.push_back(tetro);
    tetro = {{1}, {1}, {1}, {1}};
    tetrominos.push_back(tetro);
    
    tetro = {{1, 1}, {1, 1}};
    tetrominos.push_back(tetro);
    
    tetro = {{1, 0}, {1, 0}, {1, 1}};
    tetrominos.push_back(tetro);
    tetro = {{0, 1}, {0, 1}, {1, 1}};
    tetrominos.push_back(tetro);
    tetro = {{1, 1}, {0, 1}, {0, 1}};
    tetrominos.push_back(tetro);
    tetro = {{1, 1}, {1, 0}, {1, 0}};
    tetrominos.push_back(tetro);
    tetro = {{1, 1, 1}, {1, 0, 0}};
    tetrominos.push_back(tetro);
    tetro = {{1, 0, 0}, {1, 1, 1}};
    tetrominos.push_back(tetro);
    tetro = {{1, 1, 1}, {0, 0, 1}};
    tetrominos.push_back(tetro);
    tetro = {{0, 0, 1}, {1, 1, 1}};
    tetrominos.push_back(tetro);

    tetro = {{1, 0}, {1, 1}, {0, 1}};
    tetrominos.push_back(tetro);
    tetro = {{0, 1}, {1, 1}, {1, 0}};
    tetrominos.push_back(tetro);
    tetro = {{0, 1, 1}, {1, 1, 0}};
    tetrominos.push_back(tetro);
    tetro = {{1, 1, 0}, {0, 1, 1}};
    tetrominos.push_back(tetro);

    tetro = {{1, 1, 1}, {0, 1, 0}};
    tetrominos.push_back(tetro);
    tetro = {{0, 1, 0}, {1, 1, 1}};
    tetrominos.push_back(tetro);
    tetro = {{1, 0}, {1, 1}, {1, 0}};
    tetrominos.push_back(tetro);
    tetro = {{0, 1}, {1, 1}, {0, 1}};
    tetrominos.push_back(tetro);

    int maxvalue = 0;
    for(vector <vector <int>> t : tetrominos)
    {
        int y = t.size()-1;
        int x = t[0].size()-1;

        for(int i = 0; i < n-y; i++)
        {
            for(int j = 0; j < m-x; j++)
            {
                int curr_value = 0;
                for(int a = 0; a <= y; a++)
                {
                    for(int b = 0; b <= x; b++)
                    {
                        if(t[a][b])
                        {
                            curr_value += arr[i+a][j+b];
                        }
                    }
                }
                maxvalue = max(maxvalue, curr_value);
            }
        }
    }

    cout << maxvalue;   
}