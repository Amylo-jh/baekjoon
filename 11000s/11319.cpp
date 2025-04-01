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
        vector <int> arr(26);
        string str;
        getline(cin, str);
        for(int i = 0; i < str.length(); i++)
        {
            if('a' <= str[i] && str[i] <= 'z')
            {
                arr[str[i] - 'a']++;
            }
            else if('A' <= str[i] && str[i] <= 'Z')
            {
                arr[str[i] - 'A']++;
            }
        }
        
        int vowels = 0;
        vowels += arr[0] + arr[4] + arr[8] + arr[14] + arr[20];
        int consonants = 0;
        for(int i = 0; i < 26; i++)
        {
            consonants += arr[i];
        }
        consonants -= vowels;

        cout << consonants << " " << vowels << "\n";
    }
}