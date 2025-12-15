#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, answer = 0;
    vector <int> arr(26);
    string str;
    cin >> n >> str;
    for(char ch : str)
    {
        arr[ch-'A']++;
    }
    while(1)
    {
        arr['B'-'A']--;
        arr['R'-'A']--;
        arr['O'-'A']--;
        arr['N'-'A']--;
        arr['Z'-'A']--;
        arr['E'-'A']--;
        arr['S'-'A']--;
        arr['I'-'A']--;
        arr['L'-'A']--;
        arr['V'-'A']--;
        arr['E'-'A']--;
        arr['R'-'A']--;
        bool flag = false;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] < 0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            break;
        }
        answer++;
    }
    cout << answer;
}