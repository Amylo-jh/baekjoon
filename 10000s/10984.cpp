#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;

        double total_score = 0;
        int total_credit = 0;
        for(int i = 0; i < n; i++)
        {
            int curr_credit;
            double curr_score;
            cin >> curr_credit >> curr_score;
            total_credit += curr_credit;
            total_score += curr_score * curr_credit;
        }

        cout << total_credit << " " << total_score/total_credit << "\n";
    }
}