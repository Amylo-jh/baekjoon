#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> box;
    vector <int> dp;
    int n;
    int max_box = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        box.push_back(temp);
        dp.push_back(1);
    }

    for(int i = 0; i < n; i++)
    {
        int temp_box = 1;
        
        for(int j = 0; j < i; j++)
        {
            if(box[j] < box[i])
            {
                temp_box = max(temp_box, dp[j]+1);
            }
        }

        dp[i] = temp_box;
        max_box = max(max_box, temp_box);
    }

    cout << max_box;   
}