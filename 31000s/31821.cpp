#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int answer = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        answer += arr[temp];
    }

    cout << answer;
}