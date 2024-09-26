#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        string str;
        cin >> str;

        if(str == "0")
        {
            break;
        }

        vector <bool> arr(str.length()+1);
        vector <int> answer;
        for(int i = 1; i < str.length(); i++)
        {
            bool curr_state;
            if(str[i] == '0')
            {
                curr_state = false;
            }
            else
            {
                curr_state = true;
            }
            
            if(curr_state != arr[i])
            {
                answer.push_back(i);

                for(int j = i; j < str.length(); j = j+i)
                {
                    arr[j] = !arr[j];
                }
            }
        }

        for(int i : answer)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}