#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int input_num;
    int base;
    vector <int> base_nums;
    cin >> input_num >> base;

    for(int i = 0; i < base; i++)
    {
        base_nums.push_back(i);
    }

    long long decimal_permutation_num = 0;

    do{
        decimal_permutation_num = 0;
        for(int i = 0; i < base_nums.size(); i++)
        {
            if(base_nums[0] == 0)
                continue;
            
            decimal_permutation_num = decimal_permutation_num * base;
            decimal_permutation_num = decimal_permutation_num + base_nums[i];
        }
        if(decimal_permutation_num > input_num)
        {
            cout << decimal_permutation_num;
            return 0;
        }
    }while(next_permutation(base_nums.begin(), base_nums.end()));

    cout << -1;
}