#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <bool> arr;

void btrk(int idx, int cnt)
{
    if(cnt == k)
    {
        for(int i = 0; i < n; i++)
        {
            if(arr[i])
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < n; i++)
    {
        arr[i] = true;
        btrk(i+1, cnt+1);
        arr[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        arr.resize(n, false);

        cout << "The bit patterns are\n";
        btrk(0, 0);
        cout << "\n";
    }
}