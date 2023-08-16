#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <int> num(n);
    vector <int> lis(1);
    vector <int> result(n);

    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    lis[0] = num[0];
    result[0] = 0;
    int pos = 0;

    for(int i = 1; i < n; i++)
    {
        if(num[i] > lis[pos])
        {
            lis.push_back(num[i]);
            pos++;

            result[i] = pos;
        }
        else
        {
            int location = lower_bound(lis.begin(), lis.end(), num[i]) - lis.begin();
            lis[location] = num[i];

            result[i] = location;
        }
    }

    int counter = lis.size()-1;
    vector <int> final_lis(lis.size());
    for(int i = n-1; i >= 0; i--)
    {
        if(result[i] == counter)
        {
            final_lis[counter] = num[i];
            counter--;
        }
    }

    cout << final_lis.size() << "\n";
    for(int i = 0; i < final_lis.size(); i++)
    {
        cout << final_lis[i] << " ";
    }
}