#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp, sum, max_score = 0;
    cin >> n;
    vector <int> counter(100001);
    vector <int> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        counter[tmp]++;
        if(counter[tmp] <= 2)
        {
            arr.push_back(tmp);
        }
    }
    for(int i = 0; i < arr.size()-1; i++)
    {
        for(int j = i+1; j < arr.size(); j++)
        {
            tmp = arr[i] * arr[j];
            sum = 0;
            while(tmp)
            {
                sum += tmp%10;
                tmp /= 10;
            }
            max_score = max(max_score, sum);
        }
    }
    cout << max_score;
}