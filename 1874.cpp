#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack <int> num;
    stack <int> saved_num;
    vector <int> result; // 1 is push (+), 0 is pop (-), 2 is impossible
    int n;

    cin >> n;

    for(int i = n; i >= 1; i--)
    {
        num.push(i);
    }

    for(int i = 0; i < n; i++)
    {
        int curr_num;
        cin >> curr_num;

        if( !(num.empty()) && curr_num >= num.top())
        {
            while( !(num.empty()) && curr_num >= num.top())
            {
                saved_num.push(num.top());
                num.pop();
                result.push_back(1);
            }
        }
        
        if( !(saved_num.empty()) && curr_num == saved_num.top())
        {
            while(!(saved_num.empty()) &&curr_num == saved_num.top())
            {
                saved_num.pop();
                result.push_back(0);
            }
        }
        else
        {
            cout << "NO";
            result.push_back(2);
            break;
        }
    }

    if(result[result.size() - 1] != 2)
    {
        for(int i = 0; i < result.size(); i++)
        {
            if(result[i] == 1)
            {
                cout << "+\n";
            }
            else
            {
                cout << "-\n";
            }
        }
    }
}