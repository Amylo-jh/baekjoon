#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector <int> &a, vector <int> &b)
{
    if(a[1] < b[1])
    {
        return true;
    }
    if(a[1] == b[1])
    {
        if(a[0] <= b[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    return false;
}

int main()
{
    int n;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector <vector <int>> location;

    for(int i = 0; i < n; i++)
    {
        vector <int> tempvec;
        int a, b;
        cin >> a >> b;
        tempvec.push_back(a);
        tempvec.push_back(b);
        location.push_back(tempvec);
    }

    sort(location.begin(), location.end(), comp);

    for(int i = 0; i < n; i++)
    {
        cout << location[i][0] << " " << location[i][1] << "\n";
    }
}