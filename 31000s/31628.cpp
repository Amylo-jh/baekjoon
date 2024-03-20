#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <vector <string>> arr(10);
    vector <vector <bool>> visited(10);
    for(int i = 0; i < 10; i++)
    {
        arr[i].resize(10);
        visited[i].resize(10);
        for(int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }

    int counter = 0;
    for(int i = 0; i < 10; i++)
    {
        string str = arr[i][0];
        bool is_same = true;
        for(int j = 0; j < 10; j++)
        {
            if(arr[i][j] != str || visited[i][j])
            {
                is_same = false;
                break;
            }
        }
        if(is_same)
        {
            counter++;
            for(int j = 0; j < 10; j++)
            {
                visited[i][j] = true;
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        string str = arr[0][i];
        bool is_same = true;
        for(int j = 0; j < 10; j++)
        {
            if(arr[j][i] != str || visited[j][i])
            {
                is_same = false;
                break;
            }
        }
        if(is_same)
        {
            counter++;
            for(int j = 0; j < 10; j++)
            {
                visited[j][i] = true;
            }
        }
    }

    if(counter)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}
