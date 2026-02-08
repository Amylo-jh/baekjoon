#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char ch[3] = {'S', 'U', 'O'};
    cout << ch[n % 3];
}