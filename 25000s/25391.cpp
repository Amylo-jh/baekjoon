#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp (pair <int, int> a, pair <int, int> b)
{
    return a.second > b.second;
}

bool comp2 (pair <int, int> a, pair <int, int> b)
{
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int people, special_award, main_award;
    long long max_score = 0;
    cin >> people >> special_award >> main_award;

    //organizator, referee
    vector <pair <int, int>> score_info(people);

    for(int i = 0; i < people; i++)
    {
        cin >> score_info[i].first >> score_info[i].second;
    }
    
    sort(score_info.begin(), score_info.end(), comp);
    sort(score_info.begin() + main_award, score_info.end(), comp2);

    for(int i = 0; i < main_award + special_award; i++)
    {
        max_score += score_info[i].first;
    }

    cout << max_score;
}