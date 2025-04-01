#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <int>> arr(10, vector <int>(10, 1)); 
    int week;
    cin >> week;

    for(int i = 0; i < week; i++)
    {
        vector <int> cut(6);
        for(int j = 0; j < 6; j++)
        {
            cin >> cut[j];
            cut[j]--;
        }
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                arr[cut[j]][k] = 0;
            }
        }
        for(int j = 3; j < 6; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                arr[k][cut[j]] = 0;
            }
        }

        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                arr[j][k]++;
            }
        }
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}