#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> arr;
int n;

void action1(int line)
{
    int temp = arr[line][n-1];
    for(int i = n-1; i > 0; i--)
    {
        arr[line][i] = arr[line][i-1];
    }
    arr[line][0] = temp;
}

void action2()
{
    vector <vector <int>> arr2(n);
    for(int i = 0; i < n; i++)
    {
        arr2[i].resize(n);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr2[j][n-i-1] = arr[i][j];
        }
    }

    arr = arr2;
}

int main()
{
    cin >> n;

    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int query;
        cin >> query;
        if(query == 1)
        {
            int line;
            cin >> line;
            line--;
            action1(line);
        }
        else
        {
            action2();
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}