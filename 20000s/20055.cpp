#include <iostream>
#include <vector>

using namespace std;

int belt, threshold;
vector <int> durability;
vector <bool> robot;

void rotate()
{
    int last_value = durability[belt*2-1];
    for(int i = belt*2-1; i > 0; i--)
    {
        durability[i] = durability[i-1];
    }
    durability[0] = last_value;

    for(int i = belt-1; i > 0; i--)
    {
        robot[i] = robot[i-1];
    }
    robot[0] = false;
    robot[belt-1] = false;
}

void move_robot()
{
    for(int i = belt-2; i >= 0; i--)
    {
        if(robot[i] && !robot[i+1] && durability[i+1])
        {
            robot[i+1] = true;
            robot[i] = false;
            durability[i+1]--;
        }
    }
    robot[belt-1] = false;
}

void put_robot()
{
    if(durability[0])
    {
        robot[0] = true;
        durability[0]--;
    }
}

int check_belt()
{
    int counter = 0;
    for(int i = 0; i < belt*2; i++)
    {
        if(durability[i] == 0)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    cin >> belt >> threshold;
    durability.resize(2*belt);
    robot.resize(belt);
    
    for(int i = 0; i < 2*belt; i++)
    {
        cin >> durability[i];
        robot[i] = false;
    }

    int counter = 0;
    int step = 0;
    while(counter < threshold)
    {
        rotate();
        move_robot();
        put_robot();
        counter = check_belt();
        step++;
    }

    cout << step;
}