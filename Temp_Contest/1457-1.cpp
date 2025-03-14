#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Cap First, Lower Rest
    vector <int> arr = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    string str;
    int answer = 0;
    getline(cin, str);
    for(int i = 0; i < str.length(); i++)
    {
        if('A' <= str[i] && str[i] <= 'Z')
        {
            answer += arr[str[i] - 'A'];
        }
        else if('a' <= str[i] && str[i] <= 'z')
        {
            answer += arr[str[i] - 'a' + 26];
        }
        else if(str[i] == '@')
        {
            answer++;
        }
    }

    cout << answer;
}