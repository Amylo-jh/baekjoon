#include <iostream>

using namespace std;

bool check(int num)
{
    int seq = 0;
    while(num > 0)
    {
        int curr_num = num % 10;
        num /= 10;
        if(seq == 0 && curr_num == 3)
        {
            seq++;
        }
        else if(seq == 1 && curr_num == 2)
        {
            seq++;
        }
        else if(seq == 2 && curr_num == 0)
        {
            seq++;
        }
        else if(seq == 3 && curr_num == 2)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    int n, counter = 0;
    cin >> n;

    for(int i = 2023; i <= n; i++)
    {
        if(check(i))
        {
            counter++;
        }
    }

    cout << counter;
}