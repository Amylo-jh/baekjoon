#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector <vector <pair <int, int>>> parts;
vector <int> input;
vector <int> cnt;
vector <int> answer;

int main()
{
    cin >> n >> m;
    parts.resize(n+1);
    input.resize(n+1);
    cnt.resize(n+1);
    cnt[n] = 1;

    for(int i = 1; i <= m; i++)
    {
        int part, subpart, num;
        cin >> part >> subpart >> num;
        parts[part].push_back({subpart, num});
        input[subpart]++;
    }
 
    queue <int> q;
    q.push(n);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(parts[cur].empty())
        {
            answer.push_back(cur);
            continue;
        }

        for(auto p : parts[cur])
        {
            int next = p.first;
            int c = p.second;

            cnt[next] += cnt[cur]*c;
            input[next]--;
            if(!input[next])
            {
                q.push(next);
            }
        }
    }

    sort(answer.begin(), answer.end());
    for(auto i : answer)
    {
        cout << i << " " << cnt[i] << "\n";
    }
}