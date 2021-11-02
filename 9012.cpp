#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num = 0;
    string str;
    int length = 0;
    int counter = 0;
    int flag = 0;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> str;
        length = str.size();

        counter = 0;
        flag = 0;
        for (int j = 0; j < length; j++)
        {

            if(str[j] == '(')
            {
                counter++;
            }
            if(str[j] == ')')
            {
                counter--;
            }
            if(counter < 0)
            {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if(counter == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            if(flag == 1)
            {
                continue;
            }
            cout << "NO" << endl;
        }
    }
}