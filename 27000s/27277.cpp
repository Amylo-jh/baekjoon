#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int total_score = 0;
    vector <int> score(n);
    for(int i = 0; i < n; i++)
    {
        cin >> score[i];
        total_score += score[i];
    }

    sort(score.begin(), score.end());

    int minus_score = 0;
    for(int i = 0; i < n/2; i++)
    {
        minus_score += score[i] * 2;
    }
    if(n % 2 == 0)
    {
        minus_score -= score[n/2 - 1];
    }

    cout << total_score - minus_score;
}