#include <iostream>
#include <vector>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    int curr_building;
    int priv_building;
    int max_diff_score = 0;

    vector <int> curr_building_score;
    vector <int> priv_building_score;

    cin >> curr_building >> priv_building;

    for(int i = 0; i < max(curr_building, priv_building); i++)
    {
        curr_building_score.push_back(0);
        priv_building_score.push_back(0);
    }

    for(int i = 0; i < curr_building; i++)
    {
        int temp;
        cin >> temp;
        curr_building_score[i] = temp;
    }

    for(int i = 0; i < priv_building; i++)
    {
        int temp;
        cin >> temp;
        priv_building_score[i] = temp;
    }

    for(int i = 0; i < max(curr_building, priv_building); i++)
    {
        int diff = priv_building_score[i] - curr_building_score[i];
        max_diff_score = max(max_diff_score, diff);
    }

    cout << max_diff_score;
}