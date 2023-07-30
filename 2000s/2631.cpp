#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> lis(1);
    int lis_count = 0;
    cin >> lis[0];
    for(int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;

        if(temp > lis[lis_count])
        {
            lis.push_back(temp);
            lis_count++;
        }
        else
        {
            int index = lower_bound(lis.begin(), lis.end(), temp) - lis.begin();
            lis[index] = temp;
        }
    }

    cout << n - lis.size();
}