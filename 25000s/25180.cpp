#include <iostream>
using namespace std;
int main()
{
int n;
cin>>n;
cout<<(n/9)+(!!(n%9))+((n%2)&&(!(((n/9)+(!!(n%9)))%2)));
}