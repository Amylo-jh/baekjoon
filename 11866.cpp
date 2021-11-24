#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue <int> people;
    queue <int> out_people;
    int n, k;
    int temp;
    
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        people.push(i);
    }

    while(people.size() != 0)
    {
        for(int j = 0; j < k-1; j++)
        {
            temp = people.front();
            people.pop();
            people.push(temp);
        }
        temp = people.front();
        out_people.push(temp);
        people.pop();
    }

    cout << "<";
    for(int i = 0; i < n; i++)
    {
        cout << out_people.front();
        out_people.pop();

        if(i < n-1)
        {
            cout << ", ";
        }
    }
    cout << ">";
}