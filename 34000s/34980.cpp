#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, c1 = 0, c2 = 0;
    string str;
    cin >> n;
    vector <bool> arr1(n);
    vector <bool> arr2(n);
    cin >> str;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'w')
        {
            arr1[i] = true;
            c1++;
        }
    }
    cin >> str;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'w')
        {
            arr2[i] = true;
            c2++;
        }
    }

    if(arr1 == arr2)
    {
        cout << "Good";
    }
    else if(c1 == c2)
    {
        cout << "Its fine";
    }
    else if(c1 < c2)
    {
        cout << "Manners maketh man";
    }
    else if(c1 > c2)
    {
        cout << "Oryang";
    }
}