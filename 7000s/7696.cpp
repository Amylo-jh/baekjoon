#include <iostream>
#include <string>

using namespace std;

void reset_array(int (&array)[10])
{
    for(int i = 0; i < 10; i++)
    {
        array[i] = 0;
    }
}


int main()
{
    int nums[1000001] = {0};

    int index = 1;
    int num = 0;
    string temp;
    int array[10] = {0};
    bool flag = false;

    while(index <= 1000000)
    {
        flag = false;
        num++;
        reset_array(array);

        temp = to_string(num);
        for(int j = 0; j < temp.length(); j++)
        {
            array[temp[j]-48]++;
            if(array[temp[j]-48] == 2)
            {
                flag = true;
                break;
            }
        }

        if(flag)
        {
            continue;
        }

        nums[index] = num;
        index++;
    }

    int input_num = 1;
    while(1)
    {
        cin >> input_num;
        if(input_num == 0)
        {
            break;
        }
        cout << nums[input_num] << endl;
    }
}