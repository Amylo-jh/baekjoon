#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> persons;
vector <bool> truths;

vector <vector <int>> partys;
vector <bool> infected;

void bfs(int person)
{
    queue <int> bfs_queue;
    for(int i : persons[person])
    {
        bfs_queue.push(i);
    }

    while (!bfs_queue.empty())
    {
        int curr_party = bfs_queue.front();
        bfs_queue.pop();
        if(infected[curr_party])
        {
            infected[curr_party] = false;
            for(int i : partys[curr_party])
            {
                for(int j : persons[i])
                {
                    bfs_queue.push(j);
                }
            }
        }
    }
}

int main()
{
    int person;
    int party;
    int truth;
    cin >> person >> party >> truth;
    
    for(int i = 0; i <= person; i++)
    {
        vector <int> temp_person = {};
        persons.push_back(temp_person);
        truths.push_back(false);
    }
    for(int i = 0; i < party; i++)
    {
        vector <int> temp_party = {};
        partys.push_back(temp_party);
        infected.push_back(true);
    }
    for(int i = 0; i < truth; i++)
    {
        int num;
        cin >> num;
        truths[num] = true;
    }
    for(int i = 0; i < party; i++)
    {
        int num;
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            int ppl;
            cin >> ppl;
            partys[i].push_back(ppl);
            persons[ppl].push_back(i);
        }
    }

    for(int i = 0; i <= person; i++)
    {
        if(truths[i])
        {
            bfs(i);
        }
    }

    int count = 0;
    for(int i = 0; i < party; i++)
    {
        if(infected[i])
        {
            count++;
        }
    }

    cout << count;
}


/*

사람이 가지고 있는 정보 : 내가 속해 있는 파티 번호

파티 번호가 가지고 있는 정보 : 그 파티에 속해 있는 사람 번호,
                            거짓이 default, 한명이라도 있으면 bool값 변경
*/