#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int>> matrix1(n);
    for(int i = 0; i < n; i++)
    {
        matrix1[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> matrix1[i][j];
        }
    }
    int k;
    cin >> m >> k;
    vector <vector <int>> matrix2(m);
    for(int i = 0; i < m; i++)
    {
        matrix2[i].resize(k);
        for(int j = 0; j < k; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    vector <vector <int>> matrix3(n);
    for(int i = 0; i < n; i++)
    {
        matrix3[i].resize(k);
        for(int j = 0; j < k; j++)
        {
            for(int k = 0; k < m; k++)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << matrix3[i][j] << " ";
        }
        cout << "\n";
    }
}