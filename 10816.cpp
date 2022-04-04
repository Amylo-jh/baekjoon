#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    vector <int> cards;
    vector <int> query;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cards.push_back(temp);
    }
    
    sort(cards.begin(), cards.end());

    cin >> m;
    vector <int>::iterator low, up;

    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        low = lower_bound(cards.begin(), cards.end(), temp);
        up = upper_bound(cards.begin(), cards.end(), temp);

        cout << up - low << " ";
    }
}