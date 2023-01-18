#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    vector <vector <bool>> dst(n);
    for(int i = 0; i < n; i++)
    {
        dst[i].resize(n);
        int temp;
        for(int j = 0; j < n; j++)
        {
            cin >> temp;
            dst[i][j] = temp;
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dst[i][k] && dst[k][j])
                {
                    dst[i][j] = true;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << dst[i][j] << " ";
        }
        cout << "\n";
    }
}