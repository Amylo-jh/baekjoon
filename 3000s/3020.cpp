#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, h;
    cin >> n >> h;

    vector <int> up(h), lo(h);
    for(int i = 0; i < n/2; i++)
    {
        int temp;
        cin >> temp;
        lo[temp-1]++;

        cin >> temp;
        up[h-temp]++;
    }

    for(int i = h-2; i >= 0; i--)
    {
        lo[i] = lo[i+1] + lo[i];
    }
    for(int i = 1; i < h; i++)
    {
        up[i] = up[i-1] + up[i];
    }

    int min = INT32_MAX;
    int count = 0;
    for(int i = 0; i < h; i++)
    {
        int temp = lo[i] + up[i];
        if(temp < min)
        {
            min = temp;
            count = 1;
        }
        else if(temp == min)
        {
            count++;
        }
    }

    cout << min << " " << count << "\n";
}