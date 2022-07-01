#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int h;
    int w;
    cin >> h >> w;
    
    vector <vector <bool> > cloud(h, vector<bool>(w, false));
    vector <vector <int> > caster(h, vector<int>(w, -1));

    for(int i = 0; i < h; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0; j < w; j++)
        {
            if(temp[j] == 99) //c
                {
                    cloud[i][j] = true;
                }
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(cloud[i][j] == true)
            {
                int casting = 0;
                for(int k = j; k < w; k++)
                {
                    caster[i][k] = casting;
                    casting++;
                }
            }
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cout << caster[i][j] << " ";
        }
        cout << endl;
    }
    
}