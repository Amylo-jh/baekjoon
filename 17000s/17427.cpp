#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector <int> arr(n+1);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; i*j <= n; j++)
        {
            arr[i*j] += i;
        }
    }

    long long answer = 0;
    for(int i = 1; i <= n; i++)
    {
        answer += arr[i];
    }

    cout << answer;
}