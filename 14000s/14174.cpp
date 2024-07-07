#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr(26);
    for(int i = 0; i < n; i++)
    {
        vector <int> temp1(26);
        vector <int> temp2(26);
        string str1, str2;
        cin >> str1 >> str2;

        for(int j = 0; j < str1.length(); j++)
        {
            temp1[str1[j]-'a']++;
        }
        for(int j = 0 ; j < str2.length(); j++)
        {
            temp2[str2[j]-'a']++;
        }

        for(int j = 0; j < 26; j++)
        {
            arr[j] += max(temp1[j], temp2[j]);
        }
    }

    for(int i = 0; i < 26; i++)
    {
        cout << arr[i] << "\n";
    }
}