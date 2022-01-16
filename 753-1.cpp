#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string base_calc (string str, int base)
{
    long long target_num = stoll(str);

    string changed_num = "";
    
    if(target_num == 0)
    {
        changed_num = "0";
    }
    while(target_num != 0)
    {
        changed_num = to_string(target_num % base) + changed_num;
        target_num = target_num / base;
    }
    return changed_num;
}

void return_to_base10(string str, int base)
{
    long long num = 0;
    
    for(int i = 0; i < str.length(); i++)
    {
        string tempstr = str.substr(str.length()-1-i, 1);
        num = num + pow(base, i) * stoi(tempstr); 
    }
    
    cout << num;
}

bool make_nums (int base_num, vector <string> &nums, string str)
{
    vector <int> base_nums;
    for(int i = 0; i < base_num; i++)
    {
        base_nums.push_back(i);
    }
    string tempstr;
    
    string target_str = base_calc(str, base_num);

    do{
        tempstr = "";
        for(int i = 0; i < base_nums.size(); i++)
        {
            if(i == 0 && base_nums[i] == 0)
            {
                continue;
            }
            tempstr = tempstr + to_string(base_nums[i]);
        }

        if(stoll(tempstr) > stoll(target_str))
        {
            //cout << tempstr;
            return_to_base10(tempstr, base_num);
            return false;
        }

    }while(next_permutation(base_nums.begin(),base_nums.end()));

    return true;
}

int main()
{
    string str;
    int base_num;
    vector <string> nums;
    cin >> str >> base_num;

    bool flag = true;
    flag = make_nums(base_num, nums, str);

    if(flag == true)
    {
        cout << -1;
    }

}