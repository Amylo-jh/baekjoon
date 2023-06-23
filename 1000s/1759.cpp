#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
    
int l, c;
vector <char> arr;
vector <bool> btrk;

void backtracking(int pos, int depth)
{
    if(depth < l)
    {
        for(int i = pos; i <= c-(l-depth); i++)
        {
            btrk[i] = true;
            backtracking(i+1, depth+1);
            btrk[i] = false;
        }
    }
    else
    {
        string str;
        int consonant = 0;
        int vowel = 0; // a, e, i, o, u

        for(int i = 0; i < c; i++)
        {
            if(btrk[i])
            {
                str += arr[i];
                if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                {
                    vowel++;
                }
                else
                {
                    consonant++;
                }
            }
        }

        if(vowel >= 1 && consonant >= 2)
        {
            cout << str << "\n";
        }
    }
}

int main()
{
    cin >> l >> c;
    arr.resize(c);
    btrk.resize(c);

    for(int i = 0; i < c; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());


    // for(int i = 0; i <= c-l; i++)
    // {
        backtracking(0, 0);
    //}
    
}