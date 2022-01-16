#include <iostream>

using namespace std;

void parse(int num, bool (&nums)[10])
{
    while(num != 0)
    {
        nums[num%10] = true;
        num = num / 10;
    }
}

bool check_if_nums_full(bool (&nums)[10])
{
    bool flag = true;

    for(int i = 0; i < 10; i++)
    {
        flag = flag & nums[i];
    }

    return flag;
}

void try_to_sleep(int testcase)
{
    bool nums[10] = {false};
    int input_num = 0;
    cin >> input_num;
    int num = input_num;

    int count = 0;
    bool flag = false;
    while(count < 1000)
    {
        parse(num, nums);
        flag = check_if_nums_full(nums);

        if(flag)
            break;
        else
        {
            num = num + input_num;
            count++;
        }
    }
    
    if(flag)
    {
        cout << "Case #" << testcase + 1 << ": " << num << endl;
    }
    else
    {
        cout << "Case #" << testcase + 1 << ": " << "INSOMNIA" << endl;
    }
}

int main()
{
    int testcases = 0;
    cin >> testcases;
    
    for(int i = 0; i < testcases; i++)
    {
        try_to_sleep(i);
    }
}