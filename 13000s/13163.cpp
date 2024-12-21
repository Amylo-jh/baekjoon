#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();

    while(tc--)
    {
        string str;
        getline(cin, str);

        vector <string> arr;
        string temp = "";
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ')
            {
                arr.push_back(temp);
                temp = "";
            }
            else
            {
                temp += str[i];
            }
        }
        arr.push_back(temp);

        cout << "god";
        for(int i = 1; i < arr.size(); i++)
        {
            cout << arr[i];
        }
        cout << "\n";
    }
}