#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int w, a;
    cin >> w >> a;
    vector <int> arr(a);
    vector <bool> weight(400001);
    for(int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    for(int i = 0; i < a-2; i++)
    {
        for(int j = 0; j < i; j++)
        {
            weight[arr[i] + arr[j]] = true;
        }

        for(int j = i+2; j < a; j++)
        {
            int temp = w - (arr[i+1] + arr[j]);
            if(0 <= temp && temp <= 400000 && weight[temp])
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}