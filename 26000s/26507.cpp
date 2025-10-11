#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <vector <vector <int>>> arr(n, vector <vector <int>>(10, vector <int>(10)));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            string str;
            cin >> str;
            for(int k = 0; k < 10; k++)
            {
                arr[i][j][k] = str[k] - '0';
            }
        }
    }

    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        vector <vector <int>> answer(10, vector <int>(10));
        string str;
        getline(cin, str);
        for(char ch : str)
        {
            if(ch != ' ')
            {
                ch -= '0';
                for(int i = 0; i < 10; i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        answer[i][j] += arr[ch][i][j];
                    }
                }
            }
        }

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(answer[i][j] < 10)
                {
                    cout << "0";
                }
                cout << answer[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}