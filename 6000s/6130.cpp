#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    vector <int> arr(n), num(4), unmatch_num(4), unmatch_idx;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        num[arr[i]]++;
    }

    for(int i = num[1]; i < n; i++)
    {
        if(arr[i] == 1)
        {
            unmatch_idx.push_back(i);
            count++;
        }
    }
    for(int i = 0; i < num[1]; i++)
    {
        if(arr[i] != 1)
        {
            unmatch_num[arr[i]]++;
        }
    }
    for(int j : unmatch_idx)
    {
        if(unmatch_num[2])
        {
            arr[j] = 2;
            unmatch_num[2]--;
        }
        else
        {
            arr[j] = 3;
            unmatch_num[3]--;
        }
    }
    unmatch_idx.clear();

    for(int i = num[1]+num[2]; i < n; i++)
    {
        if(arr[i] == 2)
        {
            count++;
        }
    }

    cout << count;
}