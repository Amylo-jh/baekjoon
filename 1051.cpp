#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <int> > v;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        vector <int> temp;
        for(int j = 0; j < m; j++)
        {
            int a;
            scanf("%1d", &a);
            temp.push_back(a);
        }
        v.push_back(temp);
    }

    int max_size;
    int max_area = 1;
    if(n > m)
    {
        max_size = m;
    }
    else
    {
        max_size = n;
    }

    bool found = false;
    for(max_size; max_size >= 1; max_size--)
    {
        for(int i = 0; i < (n - max_size + 1); i++)
        {
            for(int j = 0; j < (m - max_size + 1); j++)
            {
                if(v[i][j] == v[i][j + max_size - 1] && v[i][j] == v[i + max_size -1][j] && v[i][j] == v[i + max_size-1][j + max_size -1])
                {
                    max_area = max_size * max_size;
                    found = true;
                    if(found)
                    {
                        break;
                    }
                }
            }
        }
        if(found)
        {
            break;
        }
    }


    cout << max_area;

}