#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <bool> arr(1000001);
    vector <pair <int, int>> num_pair(1000001);
    arr[0] = true;
    arr[1] = true;
    vector <int> prime;

    for(int i = 2; i <= 1000000; i++)
    {
        if(!arr[i])
        prime.push_back(i);
        for(int j = 2; i*j <= 1000000; j++)
        {
            arr[i*j] = true;
        }
    }

    int n;
    cin >> n;

    num_pair[0] = {-1, -1};
    num_pair[1] = {-1, -1};
    num_pair[2] = {-1, -1};
    num_pair[3] = {-1, -1};
    num_pair[4] = {2, 2};
    num_pair[5] = {2, 3};
    for(int i = 6; i <= 1000000; i += 2)
    {
        for(int j = 2; j < i; j++)
        {
            if(!arr[j] && !arr[i-j])
            {
                num_pair[i] = {j, i-j};
                break;
            }
        }
    }

    if(n % 2 == 0)
    {
        if(num_pair[n-4].first == -1)
        {
            cout << -1;
            return 0;
        }
        cout << num_pair[n-4].first << " ";
        cout << num_pair[n-4].second << " ";
        cout << num_pair[4].first << " ";
        cout << num_pair[4].second;
    }
    else
    {
        if(num_pair[n-5].first == -1)
        {
            cout << -1;
            return 0;
        }
        cout << num_pair[n-5].first << " ";
        cout << num_pair[n-5].second << " ";
        cout << num_pair[5].first << " ";
        cout << num_pair[5].second;
    }
}