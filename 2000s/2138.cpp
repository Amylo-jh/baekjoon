#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str_curr;
    string str_target;
    vector <bool> curr_state(n);
    vector <bool> test_state(n);
    vector <bool> target_state(n);
    cin >> str_curr >> str_target;

    for(int i = 0; i < n; i++)
    {
        if(str_curr[i] == '0')
        {
            curr_state[i] = false;
        }
        else
        {
            curr_state[i] = true;
        }

        if(str_target[i] == '0')
        {
            target_state[i] = false;
        }
        else
        {
            target_state[i] = true;
        }
    }
    test_state = curr_state;

    int change_count_0 = 0; // didn't changed first bulb;
    int change_count_1 = 1; // changed first bulb;
    bool issame_0 = false;
    bool issame_1 = false;

    //didn't changed first bulb
    for(int i = 1; i < n; i++)
    {
        if(test_state[i-1] != target_state[i-1])
        {
            change_count_0++;
            for(int j = i-1; j <= min(i+1, n-1); j++)
            {
                test_state[j] = !test_state[j];
            }
        }
    }
    if(test_state[n-1] == target_state[n-1])
    {
        issame_0 = true;
    }

    // changed first bulb;
    test_state = curr_state;
    test_state[0] = !test_state[0];
    test_state[1] = !test_state[1];
    for(int i = 1; i < n; i++)
    {
        if(test_state[i-1] != target_state[i-1])
        {
            change_count_1++;
            for(int j = i-1; j <= min(i+1, n-1); j++)
            {
                test_state[j] = !test_state[j];
            }
        }
    }
    if(test_state[n-1] == target_state[n-1])
    {
        issame_1 = true;
    }

    if(issame_0 || issame_1 == true)
    {
        if(!issame_0)
        {
            change_count_0 = 9999999;
        }
        if(!issame_1)
        {
            change_count_1 = 9999999;
        }
        cout << min(change_count_0, change_count_1);
    }
    else
    {
        cout << -1;
    }
}