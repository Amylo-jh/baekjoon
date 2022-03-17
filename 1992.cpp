#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

bool check_allsame(vector<vector<bool>> &sector, int x_pos, int y_pos, int segement)
{
    bool init = sector[y_pos][x_pos];

    for(int i = x_pos; i < x_pos + segement; i++)
    {
        for(int j = y_pos; j < y_pos + segement; j++)
        {
            if(init != sector[j][i])
            {
                return false;
            }
        }
    }

    return true;
}

string check_video(string output, vector<vector <bool>> &sector, int x_pos, int y_pos, int segment)
{
    bool is_same = check_allsame(sector, x_pos, y_pos, segment);
    string output_add = "0";

    if(sector[y_pos][x_pos])
    {
        output_add = "1";
    }

    if(is_same)
    {
        output = output + output_add;
    }
    else
    {
        output = output + "(";
        output = check_video(output, sector, x_pos, y_pos, segment / 2);
        output = check_video(output, sector, x_pos + segment /2, y_pos, segment / 2);
        output = check_video(output, sector, x_pos, y_pos + segment /2, segment / 2);
        output = check_video(output, sector, x_pos + segment / 2, y_pos + segment / 2, segment /2);
        output = output + ")";
    }

    return output;
}

int main()
{
    vector <vector <bool>> video;

    int n;
    cin >> n;
    getchar();

    for(int i = 0; i < n; i++)
    {
        vector <bool> tempvec;
        for (int j = 0; j < n; j++)
        {
            int temp = getchar();
            if(temp == '1')
            {
                tempvec.push_back(true);
            }
            else
            {
                tempvec.push_back(false);
            }
        }
        getchar();
        video.push_back(tempvec);
    }

    string output = "";

    output = check_video(output, video, 0, 0, n);

    cout << output;

}