#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string str;
        getline(cin, str);
        if(str == "#")
        {
            break;
        }

        int counter = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'a' || str[i] == 'A' || 
                str[i] == 'e' || str[i] == 'E' || 
                str[i] == 'i' || str[i] == 'I' || 
                str[i] == 'o' || str[i] == 'O' || 
                str[i] == 'u' || str[i] == 'U')
            {
                counter++;
            }
        }
        cout << counter << "\n";
    }
}