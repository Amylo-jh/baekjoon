#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> bin;

    while(n)
    {
        int remainder = n % 2;
        bin.push_back(remainder);
        n = n / 2;
    }

    int size = bin.size();
    int total = 0;

    for(int i = 0; i < size; i++)
    {
        total = total * 2;
        total = total + bin[i];
    }

    cout << total;
}