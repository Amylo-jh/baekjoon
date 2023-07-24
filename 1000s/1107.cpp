#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num, crash;
    cin >> num >> crash;
    vector <bool> keypad(10);
    for(int i = 0; i < crash; i++)
    {
        int temp;
        cin >> temp;
        keypad[temp] = true;
    }

    int curr_channel = 100;
    int diff = abs(num - curr_channel);

    for(int q = 0; q <= 1000000; q++)
    {
        int curr_num = q;
        int curr_diff = abs(q - num);

        bool flag = true;
        int count = 0;

        do
        {
            int digit = curr_num % 10;
            curr_num /= 10;
            count++;
            if(keypad[digit])
            {
                flag = false;
                break;
            }
        }
        while(curr_num);

        if(flag)
        {
            curr_diff += count;
            diff = min(diff, curr_diff);
        }
    }

    cout << diff;
}