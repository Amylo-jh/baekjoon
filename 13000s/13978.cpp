#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, r, tmp;
    cin >> n >> k >> r;
    vector<bool> arr(n);
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        arr[tmp - 1] = true;
    }
    int answer = 0, curr = 0;
    for (int i = 0; i < r; i++)
    {
        if (arr[i])
        {
            curr++;
        }
    }
    if (curr == 0)
    {
        answer += 2;
        arr[r - 1] = true;
        arr[r - 2] = true;
        curr = 2;
    }
    else if (curr == 1)
    {
        answer++;
        if (arr[r - 1])
        {
            arr[r - 2] = true;
        }
        else
        {
            arr[r - 1] = true;
        }
        curr = 2;
    }
    
    for (int i = r; i < n; i++)
    {
        if (arr[i - r])
        {
            curr--;
        }
        if (arr[i])
        {
            curr++;
        }
        if (curr < 2)
        {
            arr[i] = true;
            answer++;
            curr++;
        }
    }
    cout << answer;
}