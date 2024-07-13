#include <iostream>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string int_str = "";
    string sub_str = "";
    string cycle_str = "";
    long long int_num = 0;
    long long sub_num = 0;
    long long cycle_num = 0;

    int index = 0;
    for(; index < str.size(); index++)
    {
        if(str[index] != '.')
        {
            int_str += str[index];
        }
        else
        {
            index++;
            break;
        }
    }
    for(; index < str.size(); index++)
    {
        if(str[index] != '(')
        {
            sub_str += str[index];
        }
        else
        {
            index++;
            break;
        }
    }
    for(; index < str.size(); index++)
    {
        if(str[index] != ')')
        {
            cycle_str += str[index];
        }
        else
        {
            break;
        }
    }

    if(int_str != "")
    {
        int_num = stoll(int_str);
    } 
    if(sub_str != "")
    {
        sub_num = stoll(sub_str);
    }
    if(cycle_str != "")
    {
        cycle_num = stoll(cycle_str);
    }

    int sub_len = sub_str.size();
    int cycle_len = cycle_str.size();

    long long sum = int_num;
    sum = int_num * pow(10, sub_len) + sub_num;
    
    long long divider = 0;
    divider = pow(10, sub_len);
    
    if(cycle_len)
    {
        sum = sum * (pow(10, cycle_len)-1) + cycle_num;
        divider *= (pow(10, cycle_len)-1);
    }

    long long gcd_num = gcd(sum, divider);
    cout << sum/gcd_num << "/" << divider/gcd_num << endl;
}