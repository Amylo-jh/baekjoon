#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <string>> arr(n, vector <string> (3));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        vector <vector <string>> tmp1 = arr;
        vector <vector <string>> tmp2(0, vector <string> (3));
        for(int j = 0; j < 3; j++)
        {
            string s;
            cin >> s;
            for(int k = 0; k < tmp1.size(); k++)
            {
                if(s == tmp1[k][j] || s == "-")
                {
                    tmp2.push_back(tmp1[k]);
                }
            }
            tmp1 = tmp2;
            tmp2.clear();
        }   
        cout << tmp1.size() << "\n";
    }
}