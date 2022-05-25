#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    int total_score = 0;

    stack<int> score;
    stack<int> time;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        bool is_homework = false;
        cin >> is_homework;

        if(is_homework)
        {
            int curr_score;
            int curr_time;
            cin >> curr_score >> curr_time;

            score.push(curr_score);
            time.push(curr_time);
        }

        if(time.empty())
        {
            continue;
        }

        time.top()--;

        if(time.top() == 0)
        {
            total_score += score.top();

            score.pop();
            time.pop();
        }
    }

    cout << total_score;
}