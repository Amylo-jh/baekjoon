#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    a = " " + a;
    b = " " + b;
    c = " " + c;
    int a_len = a.length();
    int b_len = b.length();
    int c_len = c.length();

    vector <vector <vector <int>>> lcs(a_len);
    for(int i = 0; i < a_len; i++)
    {
        lcs[i].resize(b_len);
        for(int j = 0; j < b_len; j++)
        {
            lcs[i][j].resize(c_len);
        }
    }

    for(int i = 1; i < a_len; i++)
    {
        for(int j = 1; j < b_len; j++)
        {
            for(int k = 1; k < c_len; k++)
            {
                if(a[i] == b[j] && b[j] == c[k])
                {
                    lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
                }
                else
                {
                    lcs[i][j][k] = max(lcs[i-1][j][k], max(lcs[i][j-1][k], lcs[i][j][k-1]));
                }
            }
        }
    }

    cout << lcs[a_len-1][b_len-1][c_len-1];
}