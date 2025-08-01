#include <iostream>
#include <string>

using namespace std;

int main()
{
    for(int k = 0; k < 3; k++)
    {
        string str;
        cin >> str;
        int max_count = 1, count = 1;
        for(int i = 1; i < str.length(); i++)
        {
            if(str[i] == str[i-1])
            {
                count++;
                max_count = max(max_count, count);
            }
            else
            {
                count = 1;
            }
        }
        cout << max_count << "\n";
    }
}