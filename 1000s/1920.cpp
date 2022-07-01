#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool search_num(vector <int> &num, int query, int start, int end)
{
    bool is_exist = false;
    
    while(start <= end)
    {
        int middle = (start + end) / 2;

        if(num[middle] == query)
        {
            return true;
        }
        else if(num[middle] > query)
        {
            end = middle -1;
        }
        else if(num[middle] < query)
        {
            start = middle + 1;
        }
    }

    return false;
}

int main()
{
    int n, m;
    vector <int> num;
    vector <int> querys;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    
    sort(num.begin(), num.end());
    
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        querys.push_back(temp);
    }

    for(int i = 0; i < m; i++)
    {
        bool is_exist = false;
        is_exist = search_num(num, querys[i], 0, n-1);
        cout << is_exist << "\n";
    }

}