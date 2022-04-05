#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long total = 0;
    int xor_ed = 0;

    int query;
    cin >> query;

    for(int q = 0; q < query; q++)
    {
        int temp;
        cin >> temp;
        
        int temp2;
        switch (temp)
        {
        case 1:
            cin >> temp2;
            total = total + temp2;
            xor_ed = xor_ed ^ temp2;
            break;
        
        case 2:
            cin >> temp2;
            total = total - temp2;
            xor_ed = xor_ed ^ temp2;
            break;

        case 3:
            cout << total << "\n";
            break;
        
        case 4:
            cout << xor_ed << "\n";
            break;
            
        default:
            break;
        }
    }
}