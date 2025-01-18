#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int n = str.size();
    vector <vector <int>> sum(26, vector <int> (n+1, 0));
    for(int i = 0; i < n; i++)
    {
        int num = str[i] - 'a';
        sum[num][i+1] = 1;
    }   
    for(int i = 0; i < 26; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sum[i][j] += sum[i][j-1];
        }
    }

    int query;
    cin >> query;

    while(query--)
    {
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        int num = ch - 'a';
        r++;
        cout << sum[num][r] - sum[num][l] << '\n';
    }
}