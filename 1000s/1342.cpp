#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());

    int counter = 0;
    do{
        for(int i = 0; i < str.length() - 1; i++)
        {
            if(str[i] == str[i+1])
            {
                break;
            }
            else if(i == str.length() - 2)
            {
                counter++;
            }
        }
    }while(next_permutation(str.begin(), str.end()));

    if(str.length() == 1)
    {
        counter++;
    }
    
    cout << counter;
}