#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n; 

    vector <pair <int, int>> course(n);
    for(int i = 0; i < n; i++)
    {
        cin >> course[i].first >> course[i].second;
    }

    sort(course.begin(), course.end());

    priority_queue <int, vector<int>, greater<>> end_time;
    end_time.push(course[0].second);

    for(int i = 1; i < n; i++)
    {
        if(end_time.top() <= course[i].first)
        {
            end_time.pop();
        }
        end_time.push(course[i].second);
    }

    cout << end_time.size();
}