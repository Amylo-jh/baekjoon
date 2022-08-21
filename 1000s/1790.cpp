#include <iostream>

using namespace std;

int get_length(int num)
{
    int length = 0;
    while(num)
    {
        num /= 10;
        length++;
    }

    return length;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int num = 0;
    int length = 0;
    int result;

    while (length < k)
    {
        num++;
        length += get_length(num);
    }

    result = num;
    while (length != k)
    {
        result = result / 10;
        length--;
    }
    result = result % 10;
    
    if(num <= n)
    {
        cout << result;
    }
    else
    {
        cout << "-1";
    }
}