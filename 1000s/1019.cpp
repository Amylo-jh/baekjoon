#include <iostream>
#include <vector>

using namespace std;

vector <int> result;

void count(int num, int digit)
{
    while(num)
    {
        result[num%10] += digit;
        num /= 10;
    }
}

int main()
{
    result.resize(10);
    int num;
    cin >> num;

    int start = 1;
    int digit = 1;
    while(start <= num)
    {
        while(num % 10 != 9 && start <= num)
        {
            count(num, digit);
            num--;
        }

        if(num < start)
        {
            break;
        }

        while(start % 10 != 0 && start <= num)
        {
            count(start, digit);
            start++;
        }

        start /= 10;
        num /= 10;

        for(int i = 0; i < 10; i++)
        {
            result[i] += (num - start + 1) * digit;
        }
        digit *= 10;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << result[i] << " ";
    }
}