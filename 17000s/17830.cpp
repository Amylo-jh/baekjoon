#include <iostream>
#include <vector>
#include <string>

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
        string b;
        cin >> n >> b;
        int min_one = 1, max_one = 1;

        int max_pos = n;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(b[i] == '1' || b[i] == '?')
            {
                max_pos = min(i, max_pos);
                count++;
            }
            if(count > 1)
            {
                break;
            }
        }
        max_one = (n*2)-max_pos;
        if(max_one == n)
        {
            max_one = 1;
        }
        else if(count < 2)
        {
            max_one--;
        }
        
        max_pos = n;
        count = 0;
        for(int i = 0; i < n; i++)
        {
            if(b[i] == '1')
            {
                max_pos = min(i, max_pos);
                count++;
            }
            if(count > 1)
            {
                break;
            }
        }
        min_one = (n*2)-max_pos;
        if(min_one == n)
        {
            min_one = 1;
        }
        else if(count < 2)
        {
            min_one--;
        }

        cout << max_one << " " << min_one << "\n";
    }
}