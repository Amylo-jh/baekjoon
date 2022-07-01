#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a[8] = {0};
    int b[8] = {0};
    vector <int> nums;

    int temp;

    cin >> temp;
    for(int i = 0; i < 8; i++)
    {
        a[7-i] = temp % 10;
        temp = temp / 10;
    }

    cin >> temp;
    for(int i = 0; i < 8; i++)
    {
        b[7-i] = temp % 10;
        temp = temp / 10;
    }

    for(int i = 0; i < 8; i++)
    {
        nums.push_back(a[i]);
        nums.push_back(b[i]);
    }

    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 15-i; j++)
        {
            nums[j] = nums[j] + nums[j+1];
        }
    }

    cout << (nums[0] % 10);
    cout << (nums[1] % 10);
}