#include <iostream>
#include <vector>

using namespace std;

int n;
vector <vector <bool>> dp;
vector <int> weight;

void solve(int i, int w)
{
    if(i > n || dp[i][w])
    {
        return;
    }

    dp[i][w] = true;
    solve(i+1, w + weight[i]);
    solve(i+1, abs(w - weight[i]));
    solve(i+1, w);
}

int main()
{
    cin >> n;
    dp.resize(n+1);
    weight.resize(n);    
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
        dp[i].resize(15001);
    }
    dp[n].resize(15001);
    solve(0, 0);

    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int bead;
        cin >> bead;
        
        if(bead > 15000)
        {
            cout << "N ";
        }
        else if(dp[n][bead])
        {
            cout << "Y ";
        }
        else
        {
            cout << "N ";
        }
    }
}