#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> arr(n, vector <int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'o')
            {
                arr[i][j] = 1;
            }
            if(str[j] == '#')
            {
                arr[i][j] = 2;
            }
        }
    }

    while(1)
    {
        bool counter = false;
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == 1 && arr[i+1][j] == 0)
                {
                    arr[i][j] = 0;
                    arr[i+1][j] = 1;
                    counter = true;
                }
            }
        }

        if(counter == false)
        {
            break;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1)
            {
                cout << "o";
            }
            else if(arr[i][j] == 2)
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << "\n";
    }
}