#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc = 0;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int candidate;
        vector <int> votes;
        int max_vote = 0;
        int max_candidate = 0;
        int total_vote = 0;
        int max_count = 0;

        cin >> candidate;

        for(int i = 0; i < candidate; i++)
        {
            int vote;
            cin >> vote;
            votes.push_back(vote);
            
            total_vote = total_vote + vote;

            if(max_vote < vote)
            {
                max_vote = vote;
                max_candidate = i;
                max_count = 1;
            }
            else if(max_vote == vote)
            {
                max_count++;
            }
        }

        if(max_count > 1)
        {
            cout << "no winner" << endl;
            continue;
        }

        if(max_vote > total_vote / 2)
        {
            cout << "majority winner ";
        }
        else
        {
            cout << "minority winner ";
        }

        cout << max_candidate + 1 << endl;

    }
}