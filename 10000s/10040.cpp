#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    //cost, votes;
    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
    }
    for(int i = 0; i < m; i++)
    {
        int max_value = 0;
        cin >> max_value;
        int idx = 0, price = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j].first <= max_value)
            {
                arr[j].second++;
                break;
            }
        }
    }

    int max_vote = 0;
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        if(max_vote <= arr[i].second)
        {
            max_vote = arr[i].second;
            index = i;
        }
    }

    cout << index+1;
}