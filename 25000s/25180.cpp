#include<iostream>
int main()
{int n,a;std::cin>>n;a=(n-1)/9;std::cout<<a+(a%2&n%2)+1;}