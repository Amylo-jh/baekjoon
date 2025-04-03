#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> arr(17);
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[log2(temp)]++;
    }

    int answer = 0;
    bool flag = false;
    for(int i = 16; i > 0; i--)
    {
        arr[i-1] += arr[i] / 2;
        arr[i] %= 2;
        if(arr[i] && !flag)
        {
            flag = true;
        }
    }
    answer = arr[0] + int(flag);
    cout << answer;
}