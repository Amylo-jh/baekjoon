#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char sentence[1000001] = {0};
    int counter[26] = {0};
    int length = 0;
    int max_char = 0;
    
    cin >> sentence;

    length = strlen(sentence);
    
    int temp = 0;
    for(int i = 0; i < length; i++)
    {
        temp = sentence[i];
        if(65 <= temp && temp <= 90)
        {
            temp = temp - 65;
        }
        else
        {
            temp = temp - 97;
        }
        counter[temp]++;
    }

    temp = 0;
    bool duplicate = false;
    for(int j = 0; j < 26; j++)
    {
        if(counter[j]==0)
        {
            continue;
        }
        if(temp < counter[j])
        {
            temp = counter[j];
            max_char = j;
            duplicate = false;
        }
        else if(temp == counter[j])
        {
            duplicate = true;
        }
    }

    if(duplicate)
    {
        cout << "?";
        return 0;
    }
    cout << char(max_char + 65);
}