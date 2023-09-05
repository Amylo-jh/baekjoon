#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    vector <int> score(n);
    for(int i = 0; i < n; i++)
    {
        cin >> score[i];
    }

    long long total_price = 0;
    long long rabbit_price = 0;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int score_diff = score[i] - score[j];
            if(score_diff == 0)
            {
                continue;
            }
            else if(score_diff < 0)
            {
                score_diff *= -1;
            }

            total_price += y + ((score_diff / x) * y);
            total_price %= 998244353;
        }   
    }

    for(int i = 1; i < n; i++)
    {
        int score_diff = score[0] - score[i];
        if(score_diff >= 0)
        {
            continue;
        }
        else if(score_diff < 0)
        {
            score_diff *= -1;
            rabbit_price += y + ((score_diff / x) * y);
            rabbit_price %= 998244353;
        }
    }

    cout << total_price << " " << rabbit_price;
}