#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int num = 0, answer = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
        {
            if (num == 0)
            {
                answer++;
            }
            else
            {
                num--;
            }
        }
        else if (str[i] == '(')
        {
            num++;
        }
    }
    answer += num;
    cout << answer;
}