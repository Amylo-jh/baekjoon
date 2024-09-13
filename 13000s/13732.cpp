#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <vector <int>> arr(n, vector <int>(m));
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            if(s[j] == 'a')
            {
                arr[i][j] = 1;
            }
            else if(s[j] == '#')
            {
                arr[i][j] = 2;
            }
        }
    }

    for(int j = 0; j < m; j++)
    {
        int count = 0;
        int base = n-1;
        
        for(int i = n-1;; i--)
        {
            if(i == -1)
            {
                while(count)
                {
                    arr[base][j] = 1;
                    base--;
                    count--;
                }
                while(base >= 0)
                {
                    arr[base][j] = 0;
                    base--;
                }
                break;
            }
            if(arr[i][j] == 1)
            {
                count++;
            }
            if(arr[i][j] == 2)
            {
                while(count)
                {
                    arr[base][j] = 1;
                    base--;
                    count--;
                }
                while(base > i)
                {
                    arr[base][j] = 0;
                    base--;
                }
                base = i-1;
            }
        }

    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1)
            {
                cout << 'a';
            }
            else if(arr[i][j] == 2)
            {
                cout << '#';
            }
            else
            {
                cout << '.';
            }
        }
        cout << "\n";
    }
}