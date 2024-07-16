#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <string> arr(n);
    vector <int> head(26);
    vector <bool> answer(26);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        head[arr[i][0] - 'A']++;
    }

    for(char ch = 'A'; ch <= 'Z'; ch++)
    {
        int count = head[ch - 'A'];
        if(count > 1)
        {
            for(int i = 0; i < n; i++)
            {
                answer[max(ch, arr[i][1]) - 'A'] = true;
            }
        }
        if(count == 1)
        {
            for(int i = 0; i < n; i++)
            {
                if(arr[i][0] != ch)
                {
                    answer[max(ch, arr[i][1]) - 'A'] = true;
                }
            }
        }
    }

    int answer_count = 0;
    for(int i = 0; i < 26; i++)
    {
        if(answer[i])
        {
            answer_count++;
        }
    }

    cout << answer_count << "\n";
    for(int i = 0; i < 26; i++)
    {
        if(answer[i])
        {
            cout << char('A' + i) << " ";
        }
    }
}