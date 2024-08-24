#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <bool> prime(60000, true);
    prime[0] = false;
    
    for(int i = 2; i < 60000; i++)
    {
        if(prime[i])
        {
            for(int j = i * 2; j < 60000; j += i)
            {
                prime[j] = false;
            }
        }
    }

    string str;
    cin >> str;
    int num = 0;

    for(int i = 0; i < str.length(); i++)
    {
        if('a' <= str[i] && str[i] <= 'z')
        {
            num += str[i] - 'a' + 1;
        }
        else
        {
            num += str[i] - 'A' + 27;
        }
    }

    cout << (prime[num] ? "It is a prime word." : "It is not a prime word.") << endl;
}