#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    vector <int> a(4), b(4);
    vector <vector <int>> arr(12, vector <int>(4));
    while(tc--)
    {
        for(int i = 0; i < 4; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < 4; i++)
        {
            cin >> b[i];
        }
        arr[0] = a;
        arr[1] = {a[0], a[2], a[3], a[1]};
        arr[2] = {a[0], a[3], a[1], a[2]};
        arr[3] = {a[1], a[2], a[0], a[3]};
        arr[4] = {a[1], a[0], a[3], a[2]};
        arr[5] = {a[1], a[3], a[2], a[0]};
        arr[6] = {a[2], a[1], a[3], a[0]};
        arr[7] = {a[2], a[3], a[0], a[1]};
        arr[8] = {a[2], a[0], a[1], a[3]};
        arr[9] = {a[3], a[1], a[0], a[2]};
        arr[10] = {a[3], a[0], a[2], a[1]};
        arr[11] = {a[3], a[2], a[1], a[0]};
        
        bool flag = false;
        for(int i = 0; i < 12; i++)
        {
            if(arr[i] == b)
            {
                flag = true;
                break;
            }
        }

        if(flag)
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}