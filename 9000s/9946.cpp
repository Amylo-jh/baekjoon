#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc = 0;
    while(1)
    {
        tc++;
        int alpha[26] = {0};
        string input;
        bool flag = true;

        cin >> input;

        if(input == "END")
        {
            cin >> input;
            break;
        }

        for(int i = 0; i < input.length(); i++)
        {
            char temp = input[i];
            alpha[temp-97]++;
        }

        cin >> input;
        for(int i = 0; i < input.length(); i++)
        {
            char temp = input[i];
            alpha[temp-97]--;
        }

        for(int i = 0; i < 26; i++)
        {
            if(alpha[i] != 0)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout << "Case " << tc << ": same" << endl;
        }
        else
        {
            cout << "Case " << tc << ": different" << endl;
        }
    }
}