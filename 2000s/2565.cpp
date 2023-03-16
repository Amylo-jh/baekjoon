#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> lis;

void binary_search(int element)
{
    int start = 0;
    int end = lis.size() - 1;

    while(start < end)
    {
        int mid = (start + end) / 2;
        if(element < lis[mid])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    lis[end] = element;
}

int main()
{
    int n;
    cin >> n;
    
    vector <pair <int, int>> line(n);

    for(int i = 0; i < n; i++)
    {
        cin >> line[i].first >> line[i].second;
    }
    sort(line.begin(), line.end());

    for(int i = 0; i < n; i++)
    {
        if(lis.empty())
        {
            lis.push_back(line[i].second);
        }
        else
        {
            if(line[i].second > lis.back())
            {
                lis.push_back(line[i].second);
            }
            else
            {
                binary_search(line[i].second);
            }
        }
    }

    cout << n - lis.size();
}