#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <int> in_degree(n+1);
    vector <vector <int>> student(n+1);
    vector <bool> invite(n+1);

    for(int i = 1; i <= n; i++)
    {
        invite[i] = true;
        for(int j = 0; j < 2; j++)
        {
            int temp;
            cin >> temp;
            in_degree[temp]++;
            student[i].push_back(temp);
        }
    }

    queue <int> q;
    for(int i = 1; i <= n; i++)
    {
        if(in_degree[i] < 2)
        {
            q.push(i);
            invite[i] = false;
        }
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < 2; i++)
        {
            int next_student = student[curr][i];
            in_degree[next_student]--;

            if(invite[next_student] && in_degree[next_student] < 2)
            {
                invite[next_student] = false;
                q.push(next_student);
            }
        }
    }


    int count = 0;
    vector <int> result;
    for(int i = 1; i <= n; i++)
    {
        if(invite[i])
        {
            count++;
            result.push_back(i);
        }
    }

    if(count == 0)
    {
        cout << "0";
    }
    else
    {
        cout << result.size() << "\n";
        for(int i : result)
        {
            cout << i << " ";
        }
    }
}