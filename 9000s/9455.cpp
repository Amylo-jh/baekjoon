#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, m;
        cin >> n >> m;
        vector <vector <bool>> arr(n, vector <bool>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int tmp;
                cin >> tmp;
                arr[i][j] = bool(tmp);
            }
        }

        int answer = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[j][i])
                {
                    for(int k = j+1; k < n; k++)
                    {
                        if(!arr[k][i])
                        {
                            answer++;
                        }
                    }
                }
            }
        }

        cout << answer << "\n";
    }
}