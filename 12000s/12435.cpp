#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    int max_num = 1000000;
    vector <int> bro_count(1000001, 0);
    vector <vector <int>> bro_group(1000001);
    vector <vector <int>> sis_group(1000001);
    for(int i = 2; i <= max_num; i++)
    {
        for(int j = 2; j*i <= max_num; j++)
        {
            bro_count[j*i]++;
            bro_group[j*i].push_back(i);
        }
    }
    for(int i = 2; i <= max_num; i++)
    {
        sis_group[bro_count[i]].push_back(i);
    }

    for(int tcn = 1; tcn <= tc; tcn++)
    {
        int n, m;
        cin >> n >> m;

        int count = 0;
        int sis_num = bro_count[n];
        for(int i : sis_group[sis_num])
        {
            if(i >= n || bro_group[i].size() == 0)
            {
                count++;
                break;
            }
            if(bro_group[i].size() > 0 && bro_group[i][0] >= m)
            {
                count++;
            }
        }
        count--;

        cout << "Case #" << tcn << ": " << count << '\n';
    }
}