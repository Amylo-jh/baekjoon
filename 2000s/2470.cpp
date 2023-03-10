#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> liquid;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    liquid.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> liquid[i];
    }
    sort(liquid.begin(), liquid.end());

    int start = 0;
    int end = n-1;
    int min_sum = liquid[start] + liquid[end];
    int answer[2] = {start, end};

    while(start < end)
    {
        int sum = liquid[start] + liquid[end];

        if(abs(sum) < abs(min_sum))
        {
            answer[0] = start;
            answer[1] = end;
            min_sum = sum;
        }

        if(sum > 0)
        {
            end--;
        }
        else if(sum < 0)
        {
            start++;
        }
        else
        {
            break;
        }
    }

    cout << liquid[answer[0]] << " " << liquid[answer[1]];
}