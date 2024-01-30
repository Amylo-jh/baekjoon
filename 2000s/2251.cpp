#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dp[201][201][201];
bool visited[201][201][201];

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    queue <array<int, 3>> q;
    q.push({0, 0, C});

    vector <int> answer;
    while(!q.empty())
    {
        int a = q.front().at(0);
        int b = q.front().at(1);
        int c = q.front().at(2);
        q.pop();

        if(visited[a][b][c] == true)
        {
            continue;
        }
        visited[a][b][c] = true;

        if(a == 0)
        {
            answer.push_back(c);
        }

        // a물통에서 b물통으로 부을 때
        if(a + b > B)
        {
            q.push({a+b-B, B, c});
        }
        else
        {
            q.push({0, a+b, c});
        }

        // a물통에서 c물통으로 부을 때
        if(a + c > C)
        {
            q.push({a+c-C, b, C});
        }
        else
        {
            q.push({0, b, a+c});
        }

        // b물통에서 a물통을 부을 때
        if(b + a > A)
        {
            q.push({A, b+a-A, c});
        }
        else
        {
            q.push({a+b, 0, c});
        }

        // b물통에서 c물통으로 부을 때
        if(b + c > C)
        {
            q.push({a, b+c-C, C});
        }
        else
        {
            q.push({a, 0, b+c});
        }

        // c물통에서 a물통으로 부을 때
        if(a + c > A)
        {
            q.push({A, b, a+c-A});
        }
        else
        {
            q.push({a+c, b, 0});
        }

        // c물통에서 b물통으로 부을 때
        if(b + c > B)
        {
            q.push({a, B, b+c-B});
        }
        else
        {
            q.push({a, b+c, 0});
        }
    }

    sort(answer.begin(), answer.end());
    for(int i : answer)
    {
        cout << i << " ";
    }
}