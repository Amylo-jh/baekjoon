#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> num;
    long long subtotal = 0;
    long long product_total = 0;
    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
        subtotal = subtotal + temp;
    }

    for(int i = 0; i < n-1; i++)
    {
        subtotal = subtotal - num[i];
        product_total = product_total + num[i] * subtotal;
    }

    cout << product_total;
}