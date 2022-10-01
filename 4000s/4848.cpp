#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <string> numbers(16);
    numbers[0] = "{}";
    for(int i = 1; i < 16; i++)
    {
        string temp_str = "{";
        for(int j = 0; j < i; j++)
        {
            temp_str += numbers[j];
            if(j != i-1)
            {
                temp_str += ",";
            }
        }
        temp_str += "}";
        numbers[i] = temp_str;
    }

    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        string str;
        int num = 0;
        for(int j = 0; j < 2; j++)
        {
            cin >> str;
            for(int i = 0; i < 16; i++)
            {
                if(str == numbers[i])
                {
                    num += i;
                }
            }
        }

        cout << numbers[num] << "\n";
    }
}