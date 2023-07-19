#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    vector <vector <int>> lcs(a.length()+1);
    lcs[0].resize(b.length()+1);
    for(int i = 1; i <= a.length(); i++)
    {
        lcs[i].resize(b.length()+1);
        for(int j = 1; j <= b.length(); j++)
        {
            if(a[i-1] == b[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
            else
            {
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }

    cout << lcs[a.length()][b.length()];
}