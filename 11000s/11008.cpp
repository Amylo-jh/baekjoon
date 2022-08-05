#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int time = 0;
        string str;
        string copy;
        cin >> str >> copy;

        while(str.find(copy) != std::string::npos)
        {
            auto pos = str.find(copy);
            str.erase(pos, copy.length());
            time++;
        }

        time = time + str.length();
        cout << time << "\n";
    }
}