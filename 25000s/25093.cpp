#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++)
    {
        string s;
        cin >> s;
        int n = s.size();

        string new_string = "";
        for(int j = n; j > 0; j--)
        {
            string front = s.substr(0, j-1);
            string back = s.substr(j);
            string middle = s.substr(j-1, 1);
            new_string = front + middle + middle + back;

            if(new_string < s)
            {
                s = new_string;
                n++;
            }
        }

        cout << "Case #" << i << ": " << s << "\n";
    }
}