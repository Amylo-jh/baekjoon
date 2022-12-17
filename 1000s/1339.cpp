#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool comp(pair <char, int> a, pair <char, int> b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;

    vector <pair <char, int>> alphabet(26);
    vector <string> strs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    for(int i = 0; i < 26; i++)
    {
        alphabet[i] = {i + 65, 0};
    }

    for(int i = 0; i < n; i++)
    {
        int len = strs[i].length();
        for(int j = 0; j < len; j++)
        {
            int index = strs[i][j] - 65;
            alphabet[index].second += pow(10, len - j - 1);
        }
    }

    sort(alphabet.begin(), alphabet.end(), comp);
    for(int i = 0; i < 10; i++)
    {
        alphabet[i].second = 10 - i - 1;
    }
    sort(alphabet.begin(), alphabet.end());

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        int temp_sum = 0;
        for(int j = 0; j < strs[i].length(); j++)
        {
            int index = strs[i][j] - 65;
            temp_sum += alphabet[index].second * pow(10, strs[i].length() - j - 1);
        }
        sum += temp_sum;
    }

    cout << sum;
}