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

    vector <int> tanghulu(n+1);
    vector <int> fruit(10);
    int answer = 0;
    int used_counter = 0;
    int front_idx = 0;
    int back_idx = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> tanghulu[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int curr_fruit = tanghulu[i];
        if(used_counter < 2)
        {
            if(fruit[curr_fruit] == 0)
            {
                used_counter++;
            }
            fruit[curr_fruit]++;
            front_idx++;
        }
        else
        {
            if(fruit[curr_fruit] == 0)
            {
                while(1)
                {
                    fruit[tanghulu[back_idx]]--;
                    if(fruit[tanghulu[back_idx]] == 0)
                    {
                        used_counter--;
                        back_idx++;
                        break;
                    }
                    back_idx++;
                }
            }
            
            fruit[curr_fruit]++;
            if(fruit[curr_fruit] == 1)
            {
                used_counter++;
            }
            front_idx++;
        }

        answer = max(answer, front_idx - back_idx+1);
    }

    cout << answer;
}