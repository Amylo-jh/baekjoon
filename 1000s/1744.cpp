#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum = 0;

    int m_idx = 0;
    while(m_idx < n-1 && arr[m_idx+1] <= 0)
    {
        sum += arr[m_idx] * arr[m_idx+1];
        m_idx += 2;
    }
    m_idx--;

    int p_idx = n-1;
    while(p_idx > m_idx && arr[p_idx-1] > 1)
    {
        sum += arr[p_idx] * arr[p_idx-1];
        p_idx -= 2;
    }
    p_idx++;

    for(int i = m_idx+1; i < p_idx; i++)
    {
        sum += arr[i];
    }

    cout << sum;
}