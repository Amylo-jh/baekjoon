#include <iostream>
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
        string a, b;
        cin >> a >> b;
        cout << "Distances : ";
        int dist = 0;
        for(int i = 0; i < a.length(); i++)
        {
            dist = b[i] - a[i];
            if(dist < 0)
            {
                dist += 26;
            }
            cout << dist << " ";
        }
        cout << "\n";
    }
}