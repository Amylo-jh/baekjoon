#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int curr_val = 0;
    int prev_val = 0;
    int result = 0;
    int start = 0;
    
    cin >> curr_val;
    start = curr_val;
    for(int i = 1; i < n; i++)
    {
        prev_val = curr_val;

        cin >> curr_val;
        if(prev_val < curr_val)
        {
            result = max(result, curr_val - start);
        }
        else
        {
            start = curr_val;
        }
    }

    cout << result;
}