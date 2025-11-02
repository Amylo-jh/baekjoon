#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, l, line = 0, count = 0;
    cin >> n >> l;
    string str;
    for(int i = 0; i < n; i++)
    {
        int curr_line = 0;
        cin >> str;
        str += "0";
        for(int j = 0; j < l; j++)
        {
            if(str[j] == '1' && str[j+1] == '0')
            {
                curr_line++;
            }
        }
        if(curr_line > line)
        {
            line = curr_line;
            count = 1;
        }
        else if(curr_line == line)
        {
            count++;
        }
    }
    cout << line << " " << count;
}