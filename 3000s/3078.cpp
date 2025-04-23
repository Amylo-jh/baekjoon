#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector <queue <int>> q_array(21);
    long long answer = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int len = str.length();
        q_array[len].push(i);

        while(!q_array[len].empty() && q_array[len].front() < i-k)
        {
            q_array[len].pop();
        }
        if(!q_array[len].empty())
        {
            answer += q_array[len].size()-1;
        }
    }

    cout << answer;
}