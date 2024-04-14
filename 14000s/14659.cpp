#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int max_value = 0;
    int curr_value = 0;
    int curr_mountain = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp > curr_mountain)
        {
            curr_value = 0;
            curr_mountain = temp;
        }
        else
        {
            curr_value++;
            max_value = max(max_value, curr_value);
        }
    }

    cout << max_value;
}