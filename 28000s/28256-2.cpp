#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string str[3];
        for(int i = 0; i < 3; i++)
        {
            cin >> str[i];
        }

        queue <bool> q_choco;
        vector <pair<int, int>> pos(8);
        pos = {{0,0}, {0,1}, {0,2}, {1,2}, {2,2}, {2,1}, {2,0}, {1,0}};
        for(int i = 0; i < 8; i++)
        {
            if(str[pos[i].first][pos[i].second] == 'O')
            {
                q_choco.push(true);
            }
            else
            {
                q_choco.push(false);
            }
        }
        
        bool flag = true;
        vector <int> choco;
        for(int i = 0; i < 8; i++)
        {
            if(q_choco.front())
            {
                q_choco.push(q_choco.front());
                q_choco.pop();
            }
            else
            {
                flag = false;
                while(q_choco.front())
                {

                }
                break;
            }
        }

        if(flag)
        {
            choco.push_back(8);
        }
        else
        {
            int curr_choco = 0;
            for(int i = 0; i < 9; i++)
            {
                if(q_choco.front())
                {
                    curr_choco++;
                }
                else
                {
                    if(curr_choco != 0)
                    {
                        choco.push_back(curr_choco);
                    }
                    curr_choco = 0;
                }
                q_choco.push(q_choco.front());
                q_choco.pop();
            }
            if(!choco.empty())
            {
                sort(choco.begin(), choco.end());
            }
        }

        flag = true;
        int choco_count;
        cin >> choco_count;

        if(choco_count == 0)
        {
            if(choco.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }            
            continue;
        }

        if(choco_count > choco.size())
        {
            flag = false;

            //dummy input
            for(int i = 0; i < choco_count; i++)
            {
                int num;
                cin >> num;
            }
        }
        else
        {
            for(int i = 0; i < choco_count; i++)
            {
                int num;
                cin >> num;
                if(choco[i] != num)
                {
                    flag = false;
                }
            }
            if(choco.size() > choco_count && choco[0] != 8 && choco[choco_count] != 0)
            {
                flag = false;
            }
        }

        if(flag)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}