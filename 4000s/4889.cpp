#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    while(tc)
    {
        string str;
        cin >> str;
        if(str[0] == '-')
        {
            break;
        }

        int stk = 0;
        int answer = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '{')
            {
                stk++;
            }
            else
            {
                if(stk == 0)
                {
                    answer++;
                    stk++;
                }
                else
                {
                    stk--;
                }
            }
        }
        answer += stk/2;

        cout << tc << ". " << answer << "\n";
        tc++;
    }
}