#include <iostream>
#include <vector>

using namespace std;

int n, weight;
int min_value;
vector <int> arr;

void recursive(int remain_depth, int curr_item, int pos, int sum)
{
    if(remain_depth == 0)
    {
        if(sum == weight)
        {
            min_value = min(min_value, curr_item);
        }
        return;
    }
    
    remain_depth--;
    for(int i = pos; i < n-remain_depth; i++)
    {
        sum += arr[i];
        recursive(remain_depth, curr_item, i+1, sum);
        sum -= arr[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        min_value = INT32_MAX;
        cin >> n;
        arr.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> weight;

        for(int i = 1; i <= n; i++)
        {
            recursive(i, i, 0, 0);
        }

        if(min_value != INT32_MAX)
        {
            cout << min_value;
        }
        else
        {
            cout << "Not possible";
        }
        cout << "\n";
    }
}