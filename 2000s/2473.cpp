#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <long long> liquid(n);
    for(int i = 0; i < n; i++)
    {
        cin >> liquid[i];
    }
    sort(liquid.begin(), liquid.end());

    long long total_result = INT64_MAX;
    int answer[3] = {0, 0, 0};
    long long result = INT64_MAX;
    for(int i = 0; i < n-2; i++)
    {
        result = liquid[i];
        for(int j = i+1; j < n-1; j++)
        {
            result += liquid[j];
            
            int lo = j+1;
            int hi = n-1;
            int binary_search_result = 0;
            while(lo <= hi)
            {
                int mid = (lo+hi)/2;
                result += liquid[mid];

                if(result >= 0)
                {
                    hi = mid-1;
                }
                else if(result < 0)
                {
                    lo = mid+1;
                }
                binary_search_result = mid;

                if(abs(result) < abs(total_result))
                {
                    answer[0] = i;
                    answer[1] = j;
                    answer[2] = binary_search_result;
                    total_result = result;
                }
                result -= liquid[mid];
            }

            result -= liquid[j];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        cout << liquid[answer[i]] << " ";
    }
}