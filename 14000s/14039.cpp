#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <int>> arr(4, vector <int> (4));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sum = arr[0][0] + arr[0][1] + arr[0][2] + arr[0][3];
    bool isMagic = true;

    for(int i = 1; i < 4; i++)
    {
        if(arr[i][0] + arr[i][1] + arr[i][2] + arr[i][3] != sum)
        {
            isMagic = false;
            break;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i] != sum)
        {
            isMagic = false;
            break;
        }
    }

    if(isMagic)
    {
        cout << "magic";
    }
    else
    {
        cout << "not magic";
    }
}