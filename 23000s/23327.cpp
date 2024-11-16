#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector <int> team(n+1);
    vector <long long> team_prefix(n+1);
    vector <long long> team_square_prefix(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> team[i];
        team_square_prefix[i] = team[i] * team[i];
        team_square_prefix[i] = team_square_prefix[i] + team_square_prefix[i-1];
        team_prefix[i] = team_prefix[i-1] + team[i];
    }

    while(q--)
    {
        int l, r;
        cin >> l >> r;

        long long total_sum = 0;
        long long division_sum = team_prefix[r] - team_prefix[l-1];
        long long division_square = team_square_prefix[r] - team_square_prefix[l-1];

        total_sum = (division_sum * division_sum - division_square) / 2;
        cout << total_sum << "\n";
    }
}