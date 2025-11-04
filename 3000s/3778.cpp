#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    for(int tc = 1; tc <= n; tc++)
    {
        vector <vector <int>> arr(2, vector <int>(26));
        string str;
        for(int i = 0; i < 2; i++)
        {
            getline(cin, str);
            for(int j = 0; j < str.length(); j++)
            {
                arr[i][str[j] - 'a']++;
            }
        }
        int diff = 0;
        for(int i = 0; i < 26; i++)
        {
            diff += abs(arr[0][i] - arr[1][i]);
        }
        cout << "Case #" << tc << ": " << diff << "\n";
    }
}