//참고 : https://mygumi.tistory.com/278

#include <iostream>
#include <vector>

using namespace std;

struct perimeter
{
    int direction;
    int length;
    int sequence;
};

int main()
{
    int melon;
    cin >> melon;

    vector <perimeter> farm;

    for(int i = 0; i < 6; i++)
    {
        perimeter temp;
        cin >> temp.direction >> temp.length;
        temp.sequence = i;
        farm.push_back(temp);
    }

    perimeter longest_x = {0, 0, 0};
    perimeter longest_y = {0, 0, 0};
    perimeter internal_x = {0, 0, 0};
    perimeter internal_y = {0, 0, 0};

    // direction info
    // 1 = east = +x
    // 2 = west = -x
    // 3 = south = -y
    // 4 = north = +y

    for(int i = 0; i < 6; i++)
    {
        if((farm[i].direction == 1 || farm[i].direction == 2) && farm[i].length > longest_x.length)
        {
            longest_x = farm[i];
        }
        if((farm[i].direction == 3 || farm[i].direction == 4) && farm[i].length > longest_y.length)
        {
            longest_y = farm[i];
        }
    }

    for(int i = 0; i < 6; i++)
    {
        if(farm[i].direction == 1 || farm[i].direction == 2)
        {
            if(longest_y.length == (farm[(i + 1)%6].length + farm[(i + 5) % 6].length))
            {
                internal_x = farm[i];
            }
        }
        if(farm[i].direction == 3 || farm[i].direction == 4)
        {
            if(longest_x.length == (farm[(i + 1)%6].length + farm[(i + 5) % 6].length))
            {
                internal_y = farm[i];
            }
        }
    }

    cout << (longest_x.length * longest_y.length - internal_x.length * internal_y.length) * melon;


/*     cout << longest_x.length << endl;
    cout << longest_y.length << endl;
    cout << internal_x.length << endl;
    cout << internal_y.length << endl; */


}