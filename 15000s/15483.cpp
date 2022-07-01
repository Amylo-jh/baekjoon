#include <iostream>
#include <vector>
#include <string>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    string str1;
    string str2;

    cin >> str1 >> str2;

    vector <vector <int>> dptable;

    for(int i = 0; i <= str1.length(); i++)
    {
        vector <int> tempvec;
        for(int j = 0; j <= str2.length(); j++)
        {
            tempvec.push_back(0);
        }
        dptable.push_back(tempvec);
    }


    for(int i = 0; i <= str1.length(); i++)
    {
        for(int j = 0; j <= str2.length(); j++)
        {
            int k = 99999;
            if(i == 0)
            {
                dptable[i][j] = j;           
                continue;
            }

            if(j == 0)
            {
                dptable[i][j] = dptable[i-1][0] + 1;
                continue;
            }

            int k_insert = dptable[i][j-1] + 1;
            int k_remove = dptable[i-1][j] + 1;
            int k_replace =  dptable[i-1][j-1] + 1;

            if(str1.substr(i-1, 1) == str2.substr(j-1, 1))
            {
                k_replace--;
            }

            k = min(k, k_insert);
            k = min(k, k_remove);
            k = min(k, k_replace);

            dptable[i][j] = k;
        }
    }

    cout << dptable[str1.length()][str2.length()];
}