#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, hb_idea, hb_impl;
    cin >> n >> m;

    priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair<int, int>> > all_prob;
    priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair<int, int>> > possible_problem;
    for(int i = 0; i < n; i++)
    {
        int idea_diff;
        int impl_diff;
        bool editorial = false;
        bool data_exist = false;
        cin >> idea_diff >> impl_diff >> data_exist >> editorial;
        
        if(editorial)
        {
            if(idea_diff % 2)
            {
                idea_diff++;
            }
            idea_diff /= 2;
            impl_diff /= 2;
        }
        if(data_exist)
        {
            impl_diff = 0;
        }

        all_prob.push({idea_diff, impl_diff});
    }
    cin >> hb_idea >> hb_impl;

    long long wa_counter = 0;
    int ac_counter = 0;

    while(ac_counter < m)
    {
        while(!all_prob.empty() && all_prob.top().first <= hb_idea)
        {
            int idea_diff = all_prob.top().first;
            int impl_diff = all_prob.top().second;
            all_prob.pop();
            possible_problem.push({impl_diff, idea_diff});
        }

        if(possible_problem.empty())
        {
            break;
        }
        else
        {
            int idea_diff = possible_problem.top().second;
            int impl_diff = possible_problem.top().first;
            possible_problem.pop();

            if(impl_diff > hb_impl)
            {
                wa_counter += impl_diff - hb_impl;
            }

            hb_impl++;
            hb_idea++;
            ac_counter++;
        }
    }

    if(ac_counter < m)
    {
        cout << -1;
    }
    else
    {
        cout << wa_counter;
    }
}