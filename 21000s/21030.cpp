#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, answer = 0;
    string a, b;
    cin >> n >> a >> b;

    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == ch || b[i] == ch)
            {
                cnt++;
            }
        }

        answer = max(answer, cnt);
    }

    cout << answer;
}