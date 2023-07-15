#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int a_len = a.length();
    int b_len = b.length();

    int min_diff = INT32_MAX;
    for(int i = 0; i <= b_len-a_len; i++)
    {
        int a_index = 0;
        int curr_diff = 0;
        for(int j = i; j < i+a_len; j++)
        {
            if(a[a_index] != b[j])
            {
                curr_diff++;
            }
            a_index++;
        }

        min_diff = min(min_diff, curr_diff);
    }

    cout << min_diff;
}