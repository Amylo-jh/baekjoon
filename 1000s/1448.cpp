#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <int> stick(n);
    for(int i = 0; i < n; i++)
    {
        cin >> stick[i];
    }
    sort(stick.begin(),stick.end(), greater<>());


    for(int i = 0; i < n-2; i++)
    {
        if(stick[i] < stick[i+1] + stick[i+2])
        {
            cout << stick[i] + stick[i+1] + stick[i+2];
            return 0;
        }
    }

    cout << -1;
}