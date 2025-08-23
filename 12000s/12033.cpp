#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tcc;
    cin >> tcc;
    for(int tc = 1; tc <= tcc; tc++)
    {
        int n;
        cin >> n;
        cout << "Case #" << tc << ": ";
        vector <int> arr(n*2);
        vector <bool> used(n*2, false);
        for(int i = 0; i < n*2; i++)
        {
            cin >> arr[i];
        }

        for(int i = 0; i < 2*n; i++)
        {
            if(!used[i])
            {
                used[i] = true;
                cout << arr[i] << " ";
                for(int j = i+1; j < 2*n; j++)
                {
                    if(!used[j] && arr[j] == arr[i]/3*4)
                    {
                        used[j] = true;
                        break;
                    }
                }
            }
        }
        cout << "\n";
    }
}