#include <iostream>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    int new_number;
    int count = 0;
    int orig_number;
    cin >> n;
    
    orig_number = n;

    
    while(1)
    {
        new_number = (n % 10) * 10;
        sum = 0;
        
        while(n)
        {
            sum = sum + n % 10;
            n = n / 10;
        }
        sum = sum % 10;
        new_number += sum;
        count++;

        if(new_number == orig_number)
        {
            break;
        }

        n = new_number;
    }

    cout << count;


}