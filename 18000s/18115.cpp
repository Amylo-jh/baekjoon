#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    deque <int> cards;
    vector <int> prev_cards(n+1);
    vector <int> result(n+1);
    for(int i = 1; i <= n; i++)
    {
        cards.push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        int command;
        cin >> command;

        if(command == 1)
        {
            prev_cards[i] = cards.front();
            cards.pop_front();
        }
        else if(command == 2)
        {
            int temp = cards.front();
            cards.pop_front();
            prev_cards[i] = cards.front();
            cards.pop_front();
            cards.push_front(temp);
        }
        else
        {
            prev_cards[i] = cards.back();
            cards.pop_back();
        }
    }

    for(int i = n; i > 0; i--)
    {
        result[prev_cards[i]] = n-i+1;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }
}