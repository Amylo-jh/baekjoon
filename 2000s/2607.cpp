#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <vector <int>> arr(n, vector <int>(26));
    vector <string> str_arr(n);
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        str_arr[i] = str;
        for(int j = 0; j < str.size(); j++)
        {
            arr[i][str[j] - 'A']++;
        }
    }

    int count = 0;
    for(int i = 1; i < n; i++)
    {
        if(str_arr[0].size() == str_arr[i].size())
        {
            int diff = 0;
            for(int j = 0; j < 26; j++)
            {
                diff += abs(arr[0][j] - arr[i][j]);
            }

            if(diff <= 2)
            {
                count++;
            }
        }
        
        if(abs((int)str_arr[0].size() - (int)str_arr[i].size()) == 1)
        {
            int diff = 0;
            for(int j = 0; j < 26; j++)
            {
                diff += abs(arr[0][j] - arr[i][j]);
            }

            if(diff <= 1)
            {
                count++;
            }
        }
    }

    cout << count;
}