#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence;
    int n;
    int length;
    char charactor[26] = {0};

    cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++)
    {
        fill_n(charactor,26,0);
        getline(cin, sentence);
        //cin >> sentence;
        length = sentence.size();
        int minimum = INT32_MAX;

        for(int j = 0; j < length; j++)
        {
            if(65 <= sentence[j] && sentence[j] <= 90)
            {
                charactor[int(sentence[j]-65)]++;
            }
            else if(97 <= sentence[j] && sentence[j] <= 122)
            {
                charactor[int(sentence[j]-97)]++;
            }
        }

        for(int k = 0; k < 26; k++)
        {
            if(minimum > charactor[k])
            {
                minimum = charactor[k];
            }
        }

        switch (minimum)
        {
        case 0:
            cout << "Case " << i+1 << ": Not a pangram" << endl;
            break;
        case 1:
            cout << "Case " << i+1 << ": Pangram!" << endl;
            break;
        case 2:
            cout << "Case " << i+1 << ": Double pangram!!" << endl;
            break;
        default:
            cout << "Case " << i+1 << ": Triple pangram!!!" << endl;
            break;
        }

    }
}