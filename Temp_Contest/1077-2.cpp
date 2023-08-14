#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <string> arr(3);
    for(int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    bool flag = false;
    int pos = 0;
    for(int i = 0; i < 3; i++)
    {
        if(!(arr[i] == "Fizz" || arr[i] == "Buzz" || arr[i] == "FizzBuzz"))
        {
            flag = true;
            pos = i;
            break;
        }
    }

    if(flag)
    {
        int num = stoi(arr[pos])+3-pos;
        if(num % 3 == 0 && num % 5 == 0)
        {
            cout << "FizzBuzz";
        }
        else if(num % 3 == 0)
        {
            cout << "Fizz";
        }
        else if(num % 5 == 0)
        {
            cout << "Buzz";
        }
        else
        {
            cout << num;
        }
        return 0;
    }
}