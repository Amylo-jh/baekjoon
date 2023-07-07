#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        int curr_num = i;
        vector <int> nums;
        while(curr_num)
        {
            nums.push_back(curr_num % 10);
            curr_num /= 10;
        }

        int diff = 0;
        bool flag = true;
        if(nums.size() > 1)
        {
            diff = nums[1] - nums[0];
        }
        for(int j = 2; j < nums.size(); j++)
        {
            if(diff != (nums[j] - nums[j-1]))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            count++;
        }
    }

    cout << count;
}