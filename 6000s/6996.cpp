#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        vector <int> arr(26);
        for(int i = 0; i < s1.size(); i++)
        {
            arr[s1[i]-'a']++;
        }
        for(int i = 0; i < s2.size(); i++)
        {
            arr[s2[i]-'a']--;
        }

        bool flag = true;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] != 0)
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
        {
            cout << s1 << " & " << s2 << " are anagrams.\n";
        }
        else
        {
            cout << s1 << " & " << s2 << " are NOT anagrams.\n";
        }
    }
}