#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s, r;
    cin >> n >> s >> r;
    vector <bool> boat(n+1, true);
    vector <bool> spare(n+1, false);
    int count = 0;

    for(int i = 0; i < s; i++)
    {
        int temp;
        cin >> temp;
        boat[temp] = false;
    }
    for(int i = 0; i < r; i++)
    {
        int temp;
        cin >> temp;

        if(!boat[temp])
        {
            boat[temp] = true;
        }
        else
        {
            spare[temp] = true;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!boat[i])
        {
            if(spare[i-1])
            {
                spare[i-1] = false;
            }
            else if(spare[i+1])
            {
                spare[i+1] = false;
            }
            else
            {
                count++;
            }
        }
    }

    cout << count;
}