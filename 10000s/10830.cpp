#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    long long b;
    cin >> n >> b;

    vector <vector <vector <long long>>> matrix;
    vector <vector <long long>> temp(n, vector <long long>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> temp[i][j];
        }
    }
    matrix.push_back(temp);

    long long num = 1;
    while(pow(2, num) <= b)
    {
        vector <vector <long long>> new_matrix(n, vector <long long>(n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    new_matrix[i][j] += matrix[num-1][i][k] * matrix[num-1][k][j];
                    new_matrix[i][j] %= 1000;
                }
            }
        }
        matrix.push_back(new_matrix);
        num++;
    }

    vector <vector <long long>> answer = matrix[num-1];
    b -= pow(2, num-1);
    while(b)
    {
        if(b < pow(2, num-1))
        {
            num--;
            continue;
        }

        temp = answer;
        answer = vector <vector <long long>>(n, vector <long long>(n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    answer[i][j] += temp[i][k] * matrix[num-1][k][j];
                    answer[i][j] %= 1000;
                }
            }
        }
        b -= pow(2, num-1);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << answer[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
}