#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        int count = 0;
        char chs[5] = {'a', 'e', 'i', 'o', 'u'};
        for (auto chr : str)
        {
            for (auto ch : chs)
            {
                if (chr == ch)
                {
                    count++;
                    break;
                }
            }
        }
        cout << "The number of vowels in " << str << " is " << count << ".\n";
    }
}