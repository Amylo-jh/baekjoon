#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector <int> seq(k+1);

    int min_val = INT32_MAX;
    int min_class = 0;
    for(int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> y >> x;
        seq[i] = (y-1) + (m-x);
        if(seq[i] < min_val)
        {
            min_val = seq[i];
            min_class = i;
        }
    }

    cout << min_class;
}