#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str1;
    string str2;
    
    cin >> str1 >> str2;

    vector <int> alphabet (26);

    for(int i = 0; i < str1.length(); i++)
    {
        int a = str1[i] - 65;
        alphabet[a]++;
    }    

    for(int i = 0; i < str2.length(); i++)
    {
        int a = str2[i] - 65;
        alphabet[a]--;
    }

    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] != 0)
        {
            cout << "-1";
            return 0;
        }
    }

    int a, b;
    a = str1.length() -1;
    b = a;

    int counter = 0;
    while(a >= 0 && b >= 0)
    {
        if(str1[a] == str2[b])
        {
            a--;
            b--;
        }
        else
        {
            a--;
            counter++;
        }
    }

    cout << counter;
}