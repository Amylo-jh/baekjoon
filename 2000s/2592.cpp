#include <iostream>

using namespace std;

int main()
{
    int nums[101] = {0};
    int num[10] = {0};
    int total = 0;
    int counter = 0;
    int location = 0;

    for(int i = 0; i < 10; i++)
    {
        cin >> num[i];
        nums[num[i]/10]++;
        total = total + num[i];
    }

    cout << total/10 << endl;

    for(int i = 0; i < 101; i++)
    {
        if(counter < nums[i])
        {
            counter = nums[i];
            location = i;
        }
    }

    cout << location * 10;

    
    
}