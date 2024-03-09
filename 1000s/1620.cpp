#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    map <string, int> pokemon;
    vector <string> arr(n+1);

    for(int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        pokemon[str] = i;
        arr[i] = str;
    }

    for(int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if('0' <= str[0] && str[0] <= '9')
        {
            int num = stoi(str);
            cout << arr[num] << "\n";
        }
        else
        {
            cout << pokemon[str] << "\n";
        }
    }
}