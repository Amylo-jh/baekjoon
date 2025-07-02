#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    vector <string> b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != b[i][j*2] || a[i][j] != b[i][j*2+1])
            {
                flag = false;
                i = j = n;
                break;
            }
        }
    }

    if(flag)
    {
        cout << "Eyfa";
    }
    else
    {
        cout << "Not Eyfa";
    }
}