#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    int goodword = 0;

    cin >> n;

    for(int q = 0; q < n; q++)
    {
        string full_word;
        stack <string> stack_word;

        cin >> full_word;

        if(full_word.length() % 2)
        {
            continue;
        }

        for(int i = 0; i < full_word.length(); i++)
        {
            string tempstr = full_word.substr(i,1);

            if(stack_word.empty() == false && tempstr == stack_word.top())
            {
                stack_word.pop();
            }
            else
            {
                stack_word.push(tempstr);
            }
        }

        if(stack_word.empty())
        {
            goodword++;
        }
    }

    cout << goodword;
}