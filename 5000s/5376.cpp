#include <iostream>
#include <string>

using namespace std;

long long gcd (long long x, long long y)
{
    if(y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        string str;
        cin >> str;

        int start_pos = 0;
        int end_pos = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '(')
            {
                start_pos = i;
            }
            if(str[i] == ')')
            {
                end_pos = i;
            }
        }

        string cycle_str = "";
        long long cycle_num = 0;
        if(end_pos != 0)
        {
            cycle_str = str.substr(start_pos+1, end_pos - start_pos - 1);
            cycle_num = stoll(cycle_str);
        }

        string not_cycle_str= str.substr(2, start_pos - 2);
        long long not_cycle_num = 0;
        if(not_cycle_str != "")
        {
            not_cycle_num = stoll(not_cycle_str);
        }

        int not_cycle_length = str.length() - 2;
        int cycle_length = 0;
        if(end_pos != 0)
        {
            not_cycle_length -= end_pos - start_pos + 1;
            cycle_length = end_pos - start_pos - 1;
        }
        
        //분모 : denominator
        //분자 : numerator

        long long denominator = 0;
        long long numerator = cycle_num;
        
        if(end_pos != 0)
        {
            long long temp = not_cycle_num;
            for(int i = 0; i < cycle_length; i++)
            {
                denominator *= 10;
                denominator += 9;
                temp *= 10;

            }

            numerator += temp - not_cycle_num;
        }
        else
        {
            denominator = 1;
            numerator += not_cycle_num;
        }

        for(int i = 0; i < not_cycle_length; i++)
        {
            denominator *= 10;
        }

        long long divider = gcd(denominator, numerator);

        denominator /= divider;
        numerator /= divider;

        cout << numerator << "/" << denominator << "\n";
    }
}