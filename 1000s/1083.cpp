#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> arr;
    vector <int> seq;
    vector <int> new_arr;
    arr.reserve(50);
    seq.reserve(50);
    new_arr.reserve(50);
    int n, s;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        seq.push_back(i);
    }

    cin >> s;
    
    new_arr = arr;
    sort(new_arr.begin(), new_arr.end(), greater<>());

    for(int i = 0; i < n; i++)
    {
        int curr_seq = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[i] != new_arr[j])
            {
                curr_seq++;
            }
            else
            {
                seq[i] = curr_seq;
                break;
            }
        }
    }

    int action = 0;
    while(s && action < n)
    {
        if(arr == new_arr)
        {
            break;
        }

        int target_seq = seq[action];
        int target_index = action;
        for(int i = action; i < min(n, action + s); i++)
        {
            if(i + 1 == n)
            {
                continue;
            }
            if(target_seq > seq[i+1])
            {
                target_seq = seq[i+1];
                target_index = i+1;
            }
        }

        int temp;
        for(int i = target_index; i > action; i--)
        {
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;

            temp = seq[i];
            seq[i] = seq[i-1];
            seq[i-1] = temp;
        }

        s = s - (target_index - action);
        action++;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}