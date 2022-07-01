#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector <char> str;
bool flag = true;

bool palindrome(int end_location)
{
    if(end_location == 0)
    {
        return true;
    }
    int j = end_location-1;
    for(int i = 0; i < end_location; i++)
    {
        if(str[i] != str[j])
        {
            // cout << "IPSELENTI";
            flag = false;
            return false;
        }
        j--;
    }

    if(palindrome(end_location/2))
    {
        return true;
    }
    return false;
}

int main()
{

    int length = 0;
    int middle = 0;
    string temp;

    cin >> temp;
    copy(temp.begin(), temp.end(), back_inserter(str));

    length = str.size();

    if (palindrome(length))
    {
        cout << "AKARAKA";
    }
    else
    {
        cout << "IPSELENTI";
    }    
}