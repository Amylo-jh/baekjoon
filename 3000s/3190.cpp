#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct direction
{
    int delta_x = 1;  // 1 0 -1 0  , right, down, left, up
    int delta_y = 0;  // 0 1 0 -1  , right, down, left, up

    void move(string command)
    {
        if(command == "D") // D is right, L is left
        {
            if(delta_x != 0)
            {
                delta_y = delta_x;
                delta_x = 0;
            }
            else
            {
                delta_x = delta_y * -1;
                delta_y = 0;
            }
        }
        else //turn left
        {
            if(delta_x != 0)
            {
                delta_y = delta_x * -1;
                delta_x = 0;
            }
            else
            {
                delta_x = delta_y;
                delta_y = 0;
            }
        }
    }
};

int main()
{
    vector <vector <bool>> snake_on_map;
    vector <vector <bool>> apple;
    queue <pair<int, int>> snake;
    pair<int, int> head_location = {0, 0};
    direction curr_direction;

    int map_size;
    int apple_count;
    cin >> map_size >> apple_count;

    for(int i = 0; i < map_size; i++)
    {
        vector <bool> temp_vec;
        for(int j = 0; j < map_size; j++)
        {
            temp_vec.push_back(false);
        }
        snake_on_map.push_back(temp_vec);
        apple.push_back(temp_vec);
    }

    snake_on_map[0][0] = true;
    snake.push({0,0});

    for(int i = 0; i < apple_count; i++)
    {
        int x, y;
        cin >> x >> y;
        apple[x-1][y-1] = true;
    }

    vector <pair<int, string>> instruction;
    int move;
    cin >> move;

    for(int i = 0; i < move; i++)
    {
        int time;
        string turn;
        cin >> time >> turn;
        instruction.push_back({time, turn});
    }
    instruction.push_back({INT32_MAX, "D"});

    int max_time = 0;
    bool dead = false;

    
    int curr_time = 0;
    int inst_index = 0;

    while(!dead)
    {
        curr_time++;

        head_location.first += curr_direction.delta_x;
        head_location.second += curr_direction.delta_y;

        if(head_location.first < 0 || map_size <= head_location.first 
            || head_location.second < 0 || map_size <= head_location.second
            || snake_on_map[head_location.second][head_location.first])
            {
                max_time++;
                dead = true;
                break;
            }

        snake_on_map[head_location.second][head_location.first] = true;
        snake.push({head_location.first, head_location.second});

        if(apple[head_location.second][head_location.first])
        {
            apple[head_location.second][head_location.first] = false;
        }
        else
        {
            snake_on_map[snake.front().second][snake.front().first] = false;
            snake.pop();
        }
        max_time++;

        if(curr_time == instruction[inst_index].first)
        {
            curr_direction.move(instruction[inst_index].second);
            inst_index++;
        }
    }

    cout << max_time;    
}