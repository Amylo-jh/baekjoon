#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, k;
int max_answer = 0;
vector <bool> alpha;
vector <pair <int, vector <bool>>> words;

void dfs(int cnt, int idx)
{
    if(cnt >= k || idx == 26)
    {
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            if(words[i].first == 0)
            {
                answer++;
            }
        }
        max_answer = max(max_answer, answer);
        return;
    }

    for(int i = idx; i < 26; i++)
    {
        if(alpha[i])
        {
            alpha[i] = false;
            for(int j = 0; j < n; j++)
            {
                if(words[j].second[i])
                {
                    words[j].first--;
                }
            }
            dfs(cnt+1, i+1);

            alpha[i] = true;
            for(int j = 0; j < n; j++)
            {
                if(words[j].second[i])
                {
                    words[j].first++;
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(words[i].first == 0)
        {
            answer++;
        }
    }
    max_answer = max(max_answer, answer);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    alpha.resize(26, false);
    words.resize(n);
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        words[i].second.resize(26, false);

        for(int j = 0; j < str.size(); j++)
        {
            words[i].second[str[j]-'a'] = true;
            alpha[str[j]-'a'] = true;
        }
        for(int j = 0; j < 26; j++)
        {
            if(words[i].second[j])
            {
                words[i].first++;
            }
        }
    }

    if(k < 5)
    {
        cout << 0;
        return 0;
    }

    k -= 5;
    vector <int> already_alpha = {0, 2, 8, 13, 19};
    for(int i = 0; i < 5; i++)
    {
        alpha[already_alpha[i]] = false;
    }
    for(int i = 0; i < n; i++)
    {
        words[i].first -= 5;
        for(int j = 0; j < 5; j++)
        {
            words[i].second[already_alpha[j]] = false;
        }
    }   

    dfs(0, 0);
    cout << max_answer;
}