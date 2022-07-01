#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string a, b;
    long long total = 0;
    int size_a, size_b;
    long long total_a = 0, total_b = 0;

    cin >> a >> b;

  // scanf("%s",&a);
  //  scanf("%s",&b);

    size_a = a.length();
    size_b = b.length();

    for(int i = 0; i < size_a; i++)
    {
        total_a = total_a + (a[i] - '0');
    }
    for(int j = 0; j < size_b; j++)
    {
        total_b = total_b + (b[j] - '0');
    }

    total = total_a * total_b;
    cout << total;
}