#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector <bool> num(5000001);

void init()
{
    for(int i = 0; i <= 5000000; i++)
    {
        num[i] = true;
    }
    num[0] = false;
    num[1] = false;
    
    for(int i = 2; i <= 2500000; i++)
    {
        if(num[i])
        {
            int n = 2;
            while(i * n <= 5000000)
            {
                num[i * n] = false;
                n++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();    

    int round;
    cin >> round;

    set <int> record;
    vector <priority_queue <int>> player_queue(2);
    vector <long long> player_score(2);
    
    for(int i = 0; i < round; i++)
    {
        vector <int> player(2);
        cin >> player[0] >> player[1];
  
        for(int i = 0; i < 2; i++)
        {
            int j = !i;
            
            //규칙 2.
            if(!num[player[i]])
            {
                if(player_queue[j].size() < 3)
                {
                    player_score[j] += 1000;
                }
                else
                {
                    int temp_score[2];
                    for(int k = 0; k < 2; k++)
                    {
                        temp_score[k] = player_queue[j].top();
                        player_queue[j].pop();
                    }
                    player_score[j] += player_queue[j].top();
                    for(int k = 0; k < 2; k++)
                    {
                        player_queue[j].push(temp_score[k]);
                    }
                }
            }
            else
            {
                //규칙 3.
                if(record.count(player[i]))
                {
                    player_score[i] -= 1000;
                }
                else
                {
                    record.insert(player[i]);
                    player_queue[i].push(player[i]);
                }
            }
        }
    }

    if(player_score[0] > player_score[1])
    {
        cout << "소수의 신 갓대웅";
    }
    else if(player_score[0] < player_score[1])
    {
        cout << "소수 마스터 갓규성";
    }
    else
    {
        cout << "우열을 가릴 수 없음";
    }
}