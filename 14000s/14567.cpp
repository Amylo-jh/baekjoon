#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int subject_count;
    int prereq;
    cin >> subject_count >> prereq;

    vector <int> subject(subject_count + 1);
    vector <int> input(subject_count + 1);
    vector <vector <int>> graph(subject_count + 1);

    queue <int> q1;
    queue <int> q2;

    for(int i = 0; i < prereq; i++)
    {
        int a, b;
        cin >> a >> b;
        input[b]++;
        graph[a].emplace_back(b);
    }

    for(int i = 1; i <= subject_count; i++)
    {
        if(input[i] == 0)
        {
            q1.push(i);
            subject[i] = 1;
        }
    }

    int semester = 2;
    while (!q1.empty())
    {
        int curr_subject = q1.front();
        q1.pop();
        for(int i : graph[curr_subject])
        {
            input[i]--;
            if(input[i] == 0)
            {
                q2.push(i);
                subject[i] = semester;
            }
        }

        if(q1.empty())
        {
            q1 = q2;
            q2 = {};
            semester++;
        }
    }

    for(int i = 1; i <= subject_count; i++)
    {
        cout << subject[i] << " ";
    }
}