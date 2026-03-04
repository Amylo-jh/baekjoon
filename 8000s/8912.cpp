#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            int count = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] >= arr[j])
                {
                    count++;
                }
            }
            sum += count;
        }
        cout << sum << "\n";
    }
}