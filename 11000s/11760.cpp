#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;

    int count1 = 0, count2 = 0;
    vector <bool> used(n, false);
    for(int i = 0; i < n; i++)
    {
        if(a[i] == b[i])
        {
            count1++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(b[i] == a[j] && !used[j])
            {
                used[j] = true;
                count2++;
                break;
            }
        }
    }
    count2 -= count1;

    cout << count1 << " " << count2;
}