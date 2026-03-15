#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        int len = str.length();
        vector<vector<char>> arr(len, vector<char>(len, ' '));
        for (int i = 0; i < len; i++)
        {
            arr[0][i] = str[i];
            arr[i][0] = str[i];
            arr[len - 1][len - i - 1] = str[i];
            arr[len - i - 1][len - 1] = str[i];
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
}