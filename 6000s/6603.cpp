#include <iostream>
#include <vector>

using namespace std;

int k;
vector <int> arr;
vector <bool> visited;

void btrk(int index, int depth, vector <int> btrk_vec)
{
    if(depth == 6)
    {
        for(int i = 0; i < 6; i++)
        {
            cout << btrk_vec[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = index; i <= k - 6 + depth; i++)
        {
            btrk_vec[depth] = arr[i];
            btrk(i+1, depth+1, btrk_vec);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1)
    {        
        cin >> k;
        if(k == 0)
        {
            break;
        }

        arr.resize(k);
        visited.resize(k);
        arr.clear();
        visited.clear();

        for(int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        
        vector <int> btrk_vec(6);
        btrk(0, 0, btrk_vec);

        cout << "\n";
    }
}