#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        string aa, bb;
        cin >> n >> aa >> bb;
        vector <bool> a(n), b(n);
        for(int i = 0; i < n; i++)
        {
            if(aa[i] == '1')
            {
                a[i] = true;
            }
            if(bb[i] == '1')
            {
                b[i] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(a[i] != b[i])
            {
                count++;
                a[i] = !a[i];
                a[i+1] = !a[i+1];
            }
        }
        if(a[n-1] == b[n-1])
        {
            cout << count;
        }
        else
        {
            cout << -1;
        }
        cout << "\n";
    }
}