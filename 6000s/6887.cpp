#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int num = 1;
    while(num*num <= n)
    {
        num++;
    }
    num--;
    cout << "The largest square has side length " << num << ".";
}