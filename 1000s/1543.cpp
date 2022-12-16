#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    int counter = 0;

    int str1_len = str1.length();
    int str2_len = str2.length();

    for(int i = 0; i <= str1_len - str2_len; i++)
    {
        for(int j = 0; j < str2_len; j++)
        {
            if(str1[i+j] != str2[j])
            {
                break;
            }

            if(j == str2_len -1)
            {
                counter++;
                i += str2_len - 1;
            }
        }
    }

    cout << counter;
}