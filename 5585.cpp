#include <iostream>

using namespace std;

int main()
{
    int money;
    cin >> money;
    money = 1000 - money;

    int counter = 0;

    counter = counter + (money / 500);
    money = money % 500;

    counter = counter + (money / 100);
    money = money % 100;

    counter = counter + (money / 50);
    money = money % 50;

    counter = counter + (money / 10);
    money = money % 10;
    
    counter = counter + (money / 5);
    money = money % 5;

    counter = counter + (money / 1);
    
    cout << counter;
}