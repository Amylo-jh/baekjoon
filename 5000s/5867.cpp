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

    vector <string> lower(n);
    vector <string> upper(n);
    vector <string> original(n);

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        original[i] = str;
        sort(str.begin(), str.end());
        lower[i] = str;
        sort(str.begin(), str.end(), greater<char>()); 
        upper[i] = str;
    }
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    for(int i = 0; i < n; i++)
    {
        string str = original[i];

        sort(str.begin(), str.end());
        int lowest_index = lower_bound(upper.begin(), upper.end(), str) - upper.begin();
        sort(str.begin(), str.end(), greater<char>());
        int highest_index = upper_bound(lower.begin(), lower.end(), str) - lower.begin();

        lowest_index++;
        highest_index;
        cout << lowest_index << " " << highest_index << "\n";
    }
}