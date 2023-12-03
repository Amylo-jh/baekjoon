#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str = "WelcomeToSMUPC";
    n--;
    cout << str[n%str.length()];
}