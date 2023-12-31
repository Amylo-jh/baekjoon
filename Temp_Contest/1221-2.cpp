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
    vector <int> negative;
    vector <int> positive;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp > 0)
        {
            positive.push_back(temp);
        }
        else
        {
            negative.push_back(temp);
        }
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());

    int pos_size = positive.size();
    int neg_size = negative.size();

    vector <int> list;
    for(int i = 0; i <= n; i++)
    {
        int counter = 0;

        int pos_pos = upper_bound(positive.begin(), positive.end(), i) - positive.begin();
        int neg_pos = upper_bound(negative.begin(), negative.end(), -i) - negative.begin();

        pos_pos = pos_size - pos_pos;
        neg_pos = neg_size - neg_pos;

        if(pos_pos + neg_pos == i)
        {
            list.push_back(i);
        }
    }

    cout << list.size() << "\n";
    for(int i : list)
    {
        cout << i << " ";
    }
}