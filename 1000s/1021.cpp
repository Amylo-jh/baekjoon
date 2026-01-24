#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m, answer = 0, curr_size;
    cin >> n >> m;
    curr_size = n;
    queue <int> q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    for(int i = 0; i < m; i++)
    {
        int tmp, count = 0;
        cin >> tmp;
        while(q.front() != tmp)
        {
            q.push(q.front());
            q.pop();
            count++;
        }
        q.pop();
        answer += min(count, curr_size-count);
        curr_size--;
    }
    cout << answer;
}