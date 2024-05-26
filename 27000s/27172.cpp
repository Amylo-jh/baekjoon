#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> num(n);
    vector <int> score(1000001);
    vector <int> exist(1000001);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        exist[num[i]]++;
    }

    for(int i = 0; i < n; i++)
    {
        int curr_num = num[i];
        for(int j = 1; j*curr_num <= 1000000; j++)
        {
            if(exist[j*curr_num])
            {
                score[j*curr_num]--;
                score[curr_num]++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << score[num[i]] << " ";
    }
}