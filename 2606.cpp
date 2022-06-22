#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class computer
{
public:
    int number = 0;
    set <int> connected;
};

int main()
{
    vector <computer> computers;
    vector <bool> visited;
    queue <int> bfs;
    int infected = 0;
    int device;
    int connection;
    cin >> device >> connection;

    //0번 컴퓨터, 아무것도 없는거 인덱싱 편하게 하려고 그냥 넣음
    computer empty;
    computers.push_back(empty);

    for(int i = 1; i <= device; i++)
    {
        computer tempcomputer;
        tempcomputer.number = i;
        computers.push_back(tempcomputer);

        visited.push_back(false);
    }

    for(int i = 1; i <= connection; i++)
    {
        int device1;
        int device2;
        cin >> device1 >> device2;

        computers[device1].connected.insert(device2);
        computers[device2].connected.insert(device1);
    }

    bfs.push(1);

    while (bfs.empty() != true)
    {
        if(visited[bfs.front()])
        {
            bfs.pop();
            continue;
        }

        for(auto num : computers[bfs.front()].connected)
        {
            bfs.push(num);
        }

        visited[bfs.front()] = true;
        infected++;
        bfs.pop();        
    }
    
    infected--;
    
    cout << infected;
}