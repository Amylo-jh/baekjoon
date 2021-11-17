#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <int> apple;
    int amount = 0;
    int snake = 0;

    cin >> amount >> snake;

    int tmp;
    for(int i = 0; i < amount; i++)
    {
        scanf("%d", &tmp);
        apple.push_back(tmp);
    }
    sort(apple.begin(),apple.end());

    for(int j = 0; j < amount; j++)
    {
        if(snake >= apple[j])
        {
            snake++;
        }
        else
        {
            break;
        }
    }
    
    cout << snake;
}