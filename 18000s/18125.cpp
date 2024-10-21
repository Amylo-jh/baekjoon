#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <bool>> arr1(m, vector <bool> (n));
    vector <vector <bool>> arr2(n, vector <bool> (m));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if(temp == 1)
            {
                arr1[i][j] = true;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            if(temp == 1)
            {
                arr2[i][j] = true;
            }
        }
    }

    bool flag = true;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr1[i][j] != arr2[j][m-i-1])
            {
                flag = false;
                break;
            }
        }
    }

    if(flag)
    {
        cout << "|>___/|        /}\n";
        cout << "| O < |       / }\n";
        cout << "(==0==)------/ }\n";
        cout << "| ^  _____    |\n";
        cout << "|_|_/     ||__|\n";
    }
    else
    {
        cout << "|>___/|     /}\n";
        cout << "| O O |    / }\n";
        cout << "( =0= )\"\"\"\"  \\\n";
        cout << "| ^  ____    |\n";
        cout << "|_|_/    ||__|\n";
    }
}