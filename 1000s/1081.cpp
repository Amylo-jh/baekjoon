#include <iostream>
#include <vector>

using namespace std;

vector <long long> result;

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
    int start, end;
    cin >> start >> end;

    int digit = 1;
    while(start <= end)
    {
        while(start % 10 != 0 && start <= end)
        {
            count(start, digit);
            start++;
        }
        while(end % 10 != 9 && start <= end)
        {
            count(end, digit);
            end--;
        }
        if(start >= end)
        {
            break;
        }

        start /= 10;
        end /= 10;
        for(int i = 0; i < 10; i++)
        {
            result[i] += (end - start + 1) * digit;
        }
        digit *= 10;
    }

    long long total_sum = 0;
    for(int i = 1; i < 10; i++)
    {
        total_sum += result[i]*i;
    }
    cout << total_sum;
}