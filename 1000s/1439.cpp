#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int strlength = str.length();

    int nums[2] = {0};
    int init = 2;

    for(int i = 0; i < strlength; i++)
    {
        int temp = str[i] - 48;
        if(init != temp)
        {
            nums[temp]++;
            init = temp;
        }
    }

    if(nums[0] > nums[1])
    {
        cout << nums[1];
    }
    else
    {
        cout << nums[0];
    }
}