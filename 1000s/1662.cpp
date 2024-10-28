#include <iostream>
#include <stack>
#include <string>

using namespace std;

pair <int, int> recursion(string str, int pos)
{
    int counter = 0;
    int last_num = 0;

    while(pos < str.size())
    {
        if(str[pos] == '(')
        {
            pair <int, int> temp = recursion(str, pos+1);
            counter--;
            counter += last_num*temp.first;
            pos = temp.second;
        }
        else if(str[pos] == ')')
        {
            return {counter, pos};
        }
        else
        {
            last_num = str[pos]-'0';
            counter++;
        }
        pos++;
    }
    
    return {counter, pos};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    cout << recursion(str, 0).first;
}