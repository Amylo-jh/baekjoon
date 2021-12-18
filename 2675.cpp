#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int length;
    int repeat;
    int test_case;

    cin >> test_case;

    for(int i = 0; i < test_case; i++)
    {
        cin >> repeat;
        cin >> str;
        length = str.length();
        for(int j = 0; j < length; j++)
        {
            for(int k = 0; k < repeat; k++)
            {
                cout << str[j];
            }
        }
        cout << endl;
    }
}