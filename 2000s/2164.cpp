#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue <int> cards;
    int num;
    int temp;
    
    cin >> num;

    for(int i = 1; i <= num; i++)
    {
        cards.push(i);
    }

    while(cards.size() > 1)
    {
        cards.pop();

        temp = cards.front();
        cards.push(temp);
        cards.pop();
    }

    cout << cards.front();
}
