#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int total_weight = 0;
    cin >> n;

    vector <bool> is_measureable;
    is_measureable.reserve(1000000 * n + 2);
    is_measureable[0] = true;

    // bool is_measureable[10002];
    // is_measureable[0] = true;

    for(int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;       

        for(int j = total_weight; j >= 0; j--)
        {
            if(is_measureable[j])
            {
                is_measureable[j+weight] = true;
            }
        }
        is_measureable[weight] = true;

        total_weight += weight;
    }

    for(int i = 0; i <= total_weight + 1; i++)
    {
        if(is_measureable[i] == false)
        {
            cout << i;
            break;
        }
    }
}