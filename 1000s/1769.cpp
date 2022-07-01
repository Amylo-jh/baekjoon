#include <iostream>
#include <string>

using namespace std;

int convert = 0;

string sum_all(string nums)
{
    if(nums.length() == 1)
    {
        return nums;
    }
    
    long long sum = 0;

    for(int i = 0; i < nums.length(); i++)
    {
        string temp_s;
        temp_s = nums.substr(i,1);

        int temp = 0;
        temp = stoi(temp_s);

        sum = sum + temp;
    }
    
    nums = to_string(sum);
    convert++;

    sum_all(nums);

    return nums;
}

int main()
{
    string nums;
    cin >> nums;


    int sum = 0;
    nums = sum_all(nums);
    sum = stoi(nums);

    cout << convert << endl;

    if(sum % 3 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}