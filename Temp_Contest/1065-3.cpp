#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;

        vector <long long> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int pos = 0;
        int neg = 0;

        long long curr_sum = arr[0];
        for(int i = 1; i < n; i++)
        {
            long long curr_value = arr[i];
            if(curr_value > 0)
            {
                if(curr_sum > 0)
                {
                    pos++;
                    curr_sum = curr_value;
                }
                else
                {
                    if(curr_sum + curr_value > 0)
                    {
                        curr_sum += curr_value;
                    }
                    else
                    {
                        neg++;
                        curr_sum = curr_value;
                    }
                }
            }
            else
            {
                if(curr_sum > 0)
                {
                    if(curr_sum + curr_value > 0)
                    {
                        curr_sum += curr_value;
                    }
                    else
                    {
                        pos++;
                        curr_sum = curr_value;
                    }
                }
                else
                {
                    if(curr_value > 0)
                    {
                        neg++;
                        curr_sum = curr_value;
                    }
                    else
                    {
                        curr_sum += curr_value;
                    }
                }
            }
        }

        if(curr_sum < 0)
        {
            neg++;
        }
        else if(curr_sum > 0)
        {
            pos++;
        }

        if(pos > neg)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}